#include "ETSDrawArea.h"

#include "EyeTrackingSuite.h"
#include "ETSScotoma.h"

#include <QImageReader>
#include <QImage>
#include <QPainter>

ETSDrawArea::ETSDrawArea(QWidget *parent)
	: QLabel(parent)
	, imgLoaded(false)
	, scotoma()
	, resizeTimerId(-1)
{
}

ETSDrawArea::~ETSDrawArea()
{
}

bool ETSDrawArea::setBaseImage(QString filename)
{
	baseImgFilename = filename;
	return loadBaseImage();
}

bool ETSDrawArea::loadBaseImage()
{
	// Read the image from the filename specified.
	QImageReader imgReader(baseImgFilename);
	baseImg = imgReader.read();
	imgLoaded = !baseImg.isNull();
	if (!imgLoaded)
		return false;
	
	// Scale the base image to fit the size of the widget.
	baseImg = baseImg.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

	// Remake the prosthesis given that it relies on the base image.
	prosthesis.makeProsthesis(baseImg);
}

void ETSDrawArea::repaintDrawArea(EyeTrackingSuite * ets)
{
	if (!imgLoaded)
	{
		return;
	}
	
	if (!prosthesis.areDrawOptionsAttached())
	{
		prosthesis.attachDrawOptions(&ets->optProsthesis);
	}

	// Determine the eye position from the local position adjusted for calibration.
	QPointF finalEyePos = QPointF(gazeLocalPos.x() + ets->optCalibrationHoriz, gazeLocalPos.y() + ets->optCalibrationVert);

	// Copy the base image into the image buffer. That is, overwrite the last
	// frame's drawing with just the base image.
	img = QImage(baseImg);

	// Initialize drawing.
	QPainter painter(&img);
	painter.setBrush(Qt::black);
	
	// Remake the scotoma if the options have changed.
	if (ets->optScotoma.changed)
	{
		scotoma.makeScotoma(&ets->optScotoma);
		ets->optScotoma.changed = false;
	}

	// Remake the prosthesis if the options have changed.
	if (ets->optProsthesis.changed)
	{
		prosthesis.makeProsthesis(baseImg);
		ets->optProsthesis.changed = false;
	}

	// Reduce image quality in the area of the prosthesis.
	if (ets->optScotoma.prosthesisEnabled)
	{
		int prosthesisRadius = ets->optScotoma.radius * (ets->optScotoma.prosthesisSizePercent / 100.f);
		QRect prosthesisRect = QRect(finalEyePos.x() - prosthesisRadius, finalEyePos.y() - prosthesisRadius, prosthesisRadius * 2, prosthesisRadius * 2);
		painter.drawImage(prosthesisRect, prosthesis.getImage(), prosthesisRect);
	}

	// Draw the scotoma.
	if (ets->optScotomaEnabled)
	{
		painter.drawImage(finalEyePos - QPointF(ets->optScotoma.radius, ets->optScotoma.radius), scotoma.getImage());
	}

	// Block half of the visual field, if so desired.
	if (ets->optHalfField == 1)
	{
		painter.drawRect(0, 0, finalEyePos.x(), img.height());
	}
	else if (ets->optHalfField == 2)
	{
		painter.drawRect(finalEyePos.x(), 0, img.width() - finalEyePos.x(), img.height());
	}

	painter.end();

	// Dump the image buffer to the label's pixmap.
	setPixmap(QPixmap::fromImage(img));
	repaint();
}

void ETSDrawArea::setGazeLocalPosition(QPoint pos)
{
	gazeLocalPos = pos;
}

void ETSDrawArea::setGazeScreenPosition(QPoint pos)
{
	// We were given a screen position of the user's gaze. Save the position
	// relative to the widget.
	gazeLocalPos = mapFromGlobal(pos);
	gazeLocalPos.setY(gazeLocalPos.y() - 100);
}

void ETSDrawArea::resizeEvent(QResizeEvent * event)
{
	// This resize event will fire consistently while the user is resizing
	// the window. In order to prevent lots of expensive operations, we only
	// handle resizes after no resize events have fired for a set period of time.
	if (resizeTimerId >= 0)
		killTimer(resizeTimerId);
	resizeTimerId = startTimer(200);
}

void ETSDrawArea::timerEvent(QTimerEvent * event)
{
	// Calling loadBaseImage() re-scales the underlying image.
	loadBaseImage();

	// Prevent the timer from firing repeatedly.
	killTimer(event->timerId());
	resizeTimerId = -1;
}
