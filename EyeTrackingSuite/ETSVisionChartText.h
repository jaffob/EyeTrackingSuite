#pragma once
#include <QObject>
#include <QVector>

class ETSVisionChartText : public QObject
{

private:

	QVector<QString> texts;

public:

	ETSVisionChartText(QString filename);
	~ETSVisionChartText();

	void loadFile(QString filename);

	QString getText(unsigned int index) const;
	QString getRandomText() const;
	unsigned int getTextCount() const;
};