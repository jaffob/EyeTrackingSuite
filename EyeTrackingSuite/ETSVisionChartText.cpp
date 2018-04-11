#include "ETSVisionChartText.h"
#include <fstream>
#include <string>

ETSVisionChartText::ETSVisionChartText(QString filename)
	: texts()
{
	loadFile(filename);
	if (texts.isEmpty())
	{
		texts.append(QString("Lorem ipsum dolor sit amet."));
	}
}

ETSVisionChartText::~ETSVisionChartText()
{
}

void ETSVisionChartText::loadFile(QString filename)
{
	std::ifstream file(filename.toStdString());

	if (file.fail())
	{
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		texts.append(QString::fromStdString(line));
	}

	file.close();
}

QString ETSVisionChartText::getText(unsigned int index) const
{
	return texts[index];
}

QString ETSVisionChartText::getRandomText() const
{
	int index = qrand() % texts.size();
	return texts[index];
}

unsigned int ETSVisionChartText::getTextCount() const
{
	return texts.size();
}
