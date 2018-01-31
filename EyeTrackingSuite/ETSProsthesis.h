#pragma once
#include <QObject>
#include <QImage>

typedef struct
{
	bool changed;
	int grayLevels;
	int pixelSize;
} ETSProsthesisDrawOptions;

class ETSProsthesis : public QObject
{

private:

	QImage img;

public:

	ETSProsthesis(QObject *parent = Q_NULLPTR);
	~ETSProsthesis();

	void makeProsthesis(QImage& source, ETSProsthesisDrawOptions * options);
	void makeProsthesis_Pixel(QPainter& painter, ETSProsthesisDrawOptions * options, int x, int y);

	QImage& getImage();
};