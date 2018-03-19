#pragma once
#include <QObject>
#include <QImage>

typedef struct
{
	bool changed;
	int grayLevels;
	double pixelSize;
	int fullBlack;
	int fullWhite;
} ETSProsthesisDrawOptions;

class ETSProsthesis : public QObject
{

private:

	QImage img;
	ETSProsthesisDrawOptions * options;

public:

	ETSProsthesis(QObject *parent = Q_NULLPTR);
	~ETSProsthesis();

	void makeProsthesis(class ETSBaseImage * baseImage);
	void drawOverImage(QPainter& painter, QPointF& prosthesisCenter, int prosthesisRadius);
	QImage& getImage();

	void attachDrawOptions(ETSProsthesisDrawOptions * options);
	bool areDrawOptionsAttached() const;
};