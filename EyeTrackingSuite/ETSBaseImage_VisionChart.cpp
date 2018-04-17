#include "ETSBaseImage_VisionChart.h"
#include <QPainter>
#include "ETSPhysicalUnitSystem.h"
#include "EyeTrackingSuite.h"

const int ETSBaseImage_VisionChart::textResolvePixels = 6;
const double ETSBaseImage_VisionChart::degrees2020 = 5./60.;

ETSBaseImage_VisionChart::ETSBaseImage_VisionChart(class EyeTrackingSuite * ets, ETSPhysicalUnitSystem * physUnits)
	: ets(ets)
	, img()
	, drawAreaSize()
	, phys(physUnits)
	, nAcuities(0)
	, acNumberX(0)
{
}

ETSBaseImage_VisionChart::~ETSBaseImage_VisionChart()
{
}

bool ETSBaseImage_VisionChart::regenerateForSize(QSize drawAreaSize)
{
	this->drawAreaSize = drawAreaSize;

	// Make a new image that fills the draw area and init a painter.
	img = QImage(drawAreaSize, QImage::Format::Format_RGB32);
	QPainter painter(&img);
	
	// White background.
	painter.setBrush(Qt::white);
	painter.drawRect(0, 0, drawAreaSize.width() - 1, drawAreaSize.height() - 1);

	// Make sure we've got a unit system attached.
	if (!phys) return false;

	// Make a font to use for drawing text.
	QFont fontText = QFont(ets->getCurrentVisionChartFont());
	fontText.setBold(ets->optVisionChart.fontBold);
	double fontTextCalibrationFactor = calcFontCalibration(fontText);

	// Make a font for drawing "20/xxx" numbers.
	QFont fontAcuity = QFont("Courier");
	fontAcuity.setBold(true);
	int acNumberHeight = phys->calcDegreesToPixels(degrees2020 * 5.);
	fontAcuity.setPixelSize(acNumberHeight);
	int acNumberWidth = QFontMetrics(fontAcuity).width("20/000");

	// Use one 20/100 height as padding, and start tracking the baseline of the text.
	double padding = phys->calcDegreesToPixels(degrees2020 * 5.);
	double textBase = 0;
	QRect acNumberRect = QRect(0, 0, acNumberWidth, acNumberHeight);
	double textZoneWidth = drawAreaSize.width() - (padding * 3.) - acNumberWidth;

	acNumberX = drawAreaSize.width() - padding - acNumberWidth;

	for (int i = (signed)(nAcuities - 1); i >= 0; i--)
	{
		painter.setPen(Qt::black);

		// Get this acuity and calculate how tall it should be.
		unsigned int acuity = acuities[i];
		double degs = (acuity / 20.) * degrees2020;
		double pixs = phys->calcDegreesToPixels(degs);

		// Move down the text baseline.
		textBase += pixs + padding;

		// Stop drawing if this line of text will be outside the image.
		if (textBase >= drawAreaSize.height())
		{
			break;
		}

		// Set the font to be the desired height in pixels and draw.
		fontText.setPixelSize(pixs * fontTextCalibrationFactor);
		painter.setFont(fontText);
		painter.drawText(padding, textBase, makeTruncatedSampleString(fontText, textZoneWidth));

		// Use a warning color if the text might not be resolvable on this display.
		if (pixs < textResolvePixels)
		{
			painter.setPen(Qt::red);
		}

		// Draw acuity number.
		QString acNumberString = QString("20/") + QString::number(acuity);
		acNumberRect.moveTo(acNumberX, textBase - pixs);
		acNumberRect.setHeight(pixs);
		painter.setFont(fontAcuity);
		painter.drawText(acNumberRect, Qt::AlignRight | Qt::AlignVCenter | Qt::TextDontClip, acNumberString);

		// Add a little more padding.
		textBase += padding;
	}

	// Put in a top black border then crop the image.
	textBase = qMin<double>(textBase, drawAreaSize.height());
	painter.setPen(Qt::black);
	painter.drawLine(0, textBase - 1, drawAreaSize.width(), textBase - 1);
	painter.end();
	img = img.copy(0, 0, drawAreaSize.width(), textBase);

	painter.end();
	return true;
}

QImage ETSBaseImage_VisionChart::getImage() const
{
	return QImage(img);
}

bool ETSBaseImage_VisionChart::isValid() const
{
	return !drawAreaSize.isEmpty();
}

void ETSBaseImage_VisionChart::prosthesisPostEdit(QImage & prosthesisImg)
{
	if (acNumberX > 0)
	{
		QPainter painter(&prosthesisImg);
		QRectF r = QRectF(acNumberX, 0, img.width() - acNumberX, img.height());
		painter.drawImage(r, img, r);
		painter.end();
	}
}

void ETSBaseImage_VisionChart::setAcuities(unsigned int * acuities, unsigned int count)
{
	this->nAcuities = count;
	for (unsigned int i = 0; i < count; i++)
	{
		this->acuities[i] = acuities[i];
	}
}

unsigned int * ETSBaseImage_VisionChart::getAcuities() const
{
	return (unsigned int *)acuities;
}

unsigned int ETSBaseImage_VisionChart::getAcuitiesCount() const
{
	return nAcuities;
}

QString ETSBaseImage_VisionChart::makeTruncatedSampleString(QFont& font, int width) const
{
	QString full;

	// Get a text to show.
	if (ets->optVisionChart.textDifferent)
	{
		full = ets->visTexts.getRandomText();
	}
	else
	{
		full = ets->visTexts.getText(ets->optVisionChart.textNumber - 1);
	}

	if (ets->optVisionChart.textCapital)
	{
		full = full.toUpper();
	}

	QFontMetrics metrics = QFontMetrics(font);
	int charwidth = metrics.averageCharWidth();
	int numchars = width / charwidth;

	if (metrics.width(full, numchars) > width)
	{
		numchars /= 2;
	}

	for (; numchars < full.length(); numchars++)
	{
		if (metrics.width(full, numchars) > width)
		{
			numchars--;
			break;
		}
	}

	return full.mid(0, numchars);
}

double ETSBaseImage_VisionChart::calcFontCalibration(QFont font) const
{
	double actualSize = 0;
	QRect rect;
	char * letters = "QWERTYUIOPASDFGHJKLZXCVBNM";

	// Set an arbitrary pixel size.
	double inputSize = 200;
	font.setPixelSize(inputSize);
	QFontMetrics metrics = QFontMetrics(font);

	// Get the average height of every letter in the alphabet.
	for (unsigned int i = 0; i < 26; i++)
	{
		rect = metrics.boundingRect(letters[i]);
		actualSize += rect.height();
	}
	actualSize /= 26;

	// Calculate and return the scaling factor.
	return inputSize / actualSize;
}
