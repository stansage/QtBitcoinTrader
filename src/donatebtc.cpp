//  This file is part of Qt Bitcion Trader
//      https://github.com/JulyIGHOR/QtBitcoinTrader
//  Copyright (C) 2013-2014 July IGHOR <julyighor@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  In addition, as a special exception, the copyright holders give
//  permission to link the code of portions of this program with the
//  OpenSSL library under certain conditions as described in each
//  individual source file, and distribute linked combinations including
//  the two.
//
//  You must obey the GNU General Public License in all respects for all
//  of the code used other than OpenSSL. If you modify file(s) with this
//  exception, you may extend this exception to your version of the
//  file(s), but you are not obligated to do so. If you do not wish to do
//  so, delete this exception statement from your version. If you delete
//  this exception statement from all source files in the program, then
//  also delete it here.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "donatebtc.h"
#include <QClipboard>
#include "main.h"

DonateBTC::DonateBTC(QPushButton *button, bool btc)
	: QMenu()
{
	ui.setupUi(this);
	isBtc=btc;
	if(btc)
	{
		ui.btcLabel11->setPixmap(QPixmap(":/Resources/CurrencySign/BTC.png"));
		ui.bitcoinAddress->setText("1d6iMwjjNo8ZGYeJBZKXgcgVk9o7fXcjc");
	}
	else//ltc
	{
		ui.btcLabel11->setPixmap(QPixmap(":/Resources/CurrencySign/LTC.png"));
		ui.bitcoinAddress->setText("LPJZTHaHdMwm4kHV6WGNegmoWDSzC9rzYB");
	}
	setAttribute(Qt::WA_DeleteOnClose,true);
	connect(this,SIGNAL(setCheckedButton(bool)),button,SLOT(setChecked(bool)));
	connect(this,SIGNAL(aboutToHide()),this,SLOT(aboutToHideWindow()));
	julyTranslator.translateUi(this);
	mainWindow.fixAllChildButtonsAndLabels(this);
	setFixedHeight(minimumSizeHint().height());
	setFixedWidth(width());
	QPalette pal=palette();
	pal.setColor(QPalette::Window, QColor(80,80,80));
	setPalette(pal);
}

DonateBTC::~DonateBTC()
{

}

void DonateBTC::mouseReleaseEvent(QMouseEvent *event)
{
	event->ignore();
}

void DonateBTC::aboutToHideWindow()
{
	emit setCheckedButton(false);
}

void DonateBTC::on_copyDonateButton_clicked()
{
	QApplication::clipboard()->setText(ui.bitcoinAddress->text());
}