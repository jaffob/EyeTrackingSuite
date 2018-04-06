#include "ETSVisionChartLetters.h"
#include <QImageReader>

ETSVisionChartLetters::ETSVisionChartLetters(QString filename)
{
	// Read the image from the filename specified.
	QImageReader imgReader(filename);
	img = imgReader.read();
	loaded = !img.isNull();

	if (loaded)
	{
		generateLetterSets();
	}
}

ETSVisionChartLetters::~ETSVisionChartLetters()
{
}

bool ETSVisionChartLetters::isLoaded() const
{
	return loaded;
}

ETSVisionChartLetterSet ETSVisionChartLetters::getLetterSet(unsigned int index) const
{
	return sets[index];
}

QImage ETSVisionChartLetters::getLetterSheetImage() const
{
	return QImage(img);
}

void ETSVisionChartLetters::drawRandomLetter(QPainter & painter, QPoint bottomLeft, int height) const
{

}

void ETSVisionChartLetters::generateLetterSets()
{
	nSets = 0;

	// Read letter sets from the indicator pixels in the leftmost column.
	for (int j = 0; j < img.height(); j++)
	{
		QColor pix = img.pixelColor(0, j);
		if (pix != QColor(255, 255, 255))
		{
			sets[nSets].letterWidth = pix.red();
			sets[nSets].letterHeight = pix.green();
			sets[nSets].letterCount = pix.blue();
			sets[nSets].yTop = j;

			nSets++;
		}
	}
}

QRect ETSVisionChartLetters::calcLetterBounds(unsigned int setIndex, unsigned int letterIndex) const
{
	return QRect(1 + (sets[setIndex].letterWidth + 1) * letterIndex, sets[setIndex].yTop, sets[setIndex].letterWidth, sets[setIndex].letterHeight);
}
