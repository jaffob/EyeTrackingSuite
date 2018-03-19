#pragma once
#include <QObject>
#include <QImage>

typedef struct
{
	bool changed;
	int radius;
	int sizeDegrees;
	bool prosthesisEnabled;
	int prosthesisSizePercent;
	bool gradientEnabled;
	bool gradientSquaredFalloff;
	int gradientInside;
	int gradientOutside;
} ETSScotomaDrawOptions;

class ETSScotoma : public QObject
{

private:

	QImage img;

public:

	ETSScotoma(QObject *parent = Q_NULLPTR);
	~ETSScotoma();

	/**
	 * Internally draw a scotoma into a QImage, based on the scotoma draw options.
	 */
	void makeScotoma(ETSScotomaDrawOptions * options);
	QImage& getImage();
};