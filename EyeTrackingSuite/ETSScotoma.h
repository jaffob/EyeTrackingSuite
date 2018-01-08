#pragma once
#include <QObject>
#include <QImage>

typedef struct
{
	int radius;
	bool prosthesisEnabled;
	int prosthesisSizePercent;
	int prosthesisGrayLevel;
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