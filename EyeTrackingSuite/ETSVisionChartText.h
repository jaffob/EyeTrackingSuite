#pragma once
#include <QObject>

class ETSVisionChartText : public QObject
{

public:

	ETSVisionChartText(QString filename);
	~ETSVisionChartText();

	QString getText(unsigned int index) const;
	QString getRandomText() const;
	unsigned int getTextCount() const;

};