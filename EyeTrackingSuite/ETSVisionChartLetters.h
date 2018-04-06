#pragma once
#include <QObject>
#include <QImage>
#include <QPainter>

typedef struct
{
	int letterWidth;
	int letterHeight;
	int letterCount;
	int yTop;
} ETSVisionChartLetterSet;

class ETSVisionChartLetters : public QObject
{

private:

	QImage img;
	ETSVisionChartLetterSet sets[8];
	unsigned int nSets;

	bool loaded;

public:

	ETSVisionChartLetters(QString filename);
	~ETSVisionChartLetters();

	bool isLoaded() const;

	ETSVisionChartLetterSet getLetterSet(unsigned int index) const;
	QImage getLetterSheetImage() const;

	void drawRandomLetter(QPainter& painter, QPoint bottomLeft, int height) const;


protected:

	/**
	 * One data has been loaded into img, generate letter sets.
	 */
	virtual void generateLetterSets();

	/**
	 * Get the bounding rectangle of a letter.
	 */
	virtual QRect calcLetterBounds(unsigned int setIndex, unsigned int letterIndex) const;

};