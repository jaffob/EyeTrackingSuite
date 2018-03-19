#include "ETSBaseImage_VisionChart.h"
#include <QPainter>
#include "ETSPhysicalUnitSystem.h"

const int ETSBaseImage_VisionChart::textResolvePixels = 10;
const double ETSBaseImage_VisionChart::degrees2020 = 5./60.;

ETSBaseImage_VisionChart::ETSBaseImage_VisionChart(ETSPhysicalUnitSystem * physUnits)
	: img()
	, drawAreaSize()
	, phys(physUnits)
	, nAcuities(0)
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
	QFont fontText = QFont("Lucida Sans Typewriter");

	// Make a font for drawing "20/xxx" numbers.
	QFont fontAcuity = QFont("Courier");
	fontAcuity.setBold(true);
	int acNumberHeight = phys->calcDegreesToPixels(degrees2020 * 5.);
	fontAcuity.setPixelSize(acNumberHeight);
	int acNumberWidth = QFontMetrics(fontAcuity).width("20/000");

	// Use one 20/100 height as padding, and start tracking the baseline of the text.
	double padding = phys->calcDegreesToPixels(degrees2020 * 5.);
	double textBase = drawAreaSize.height() - padding;
	QRect acNumberRect = QRect(0, 0, acNumberWidth, acNumberHeight);
	double textZoneWidth = drawAreaSize.width() - (padding * 3.) - acNumberWidth;

	for (unsigned int i = 0; i < nAcuities; i++)
	{
		painter.setPen(Qt::black);

		// Get this acuity and calculate how tall it should be.
		unsigned int acuity = acuities[i];
		double degs = (acuity / 20.) * degrees2020;
		double pixs = phys->calcDegreesToPixels(degs);

		// Set the font to be the desired height in pixels and draw.
		fontText.setPixelSize(pixs);
		painter.setFont(fontText);
		painter.drawText(padding, textBase, makeTruncatedSampleString(fontText, textZoneWidth));

		// Use a warning color if the text might not be resolvable on this display.
		if (pixs < textResolvePixels)
		{
			painter.setPen(Qt::red);
		}

		// Draw acuity number.
		QString acNumberString = QString("20/") + QString::number(acuity);
		acNumberRect.moveTo(drawAreaSize.width() - padding - acNumberWidth, textBase - pixs);
		acNumberRect.setHeight(pixs);
		painter.setFont(fontAcuity);
		painter.drawText(acNumberRect, Qt::AlignRight | Qt::AlignVCenter | Qt::TextDontClip, acNumberString);

		// Move up the text base.
		textBase -= pixs + padding * 2;
	}

	// Put in a top black border then crop the image.
	textBase += padding * 2;
	painter.setPen(Qt::black);
	painter.drawLine(0, textBase, drawAreaSize.width(), textBase);
	painter.end();
	img = img.copy(0, textBase, drawAreaSize.width(), drawAreaSize.height() - textBase + 1);

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

QString ETSBaseImage_VisionChart::makeTruncatedSampleString(QFont & font, int width) const
{
	QString full = QString("The quick brown fox jumps over the lazy dog. Then it sees a cat and it jumps over that too! Finally, in its exhaustion, it realizes the futility of its actions and decides to pursue a degree in philosophy.");
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
