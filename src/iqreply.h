/****************************************************************************
**
** qutIM instant messenger
**
** Copyright (C) 2011 Ruslan Nigmatullin <euroelessar@ya.ru>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/

#ifndef IQREPLY_H
#define IQREPLY_H

#include "jreen.h"

namespace Jreen
{
class Client;
class ClientPrivate;
class IQ;
class IQReplyPrivate;

class IQReply : public QObject
{
    Q_OBJECT
	Q_DECLARE_PRIVATE(IQReply)
public:
	~IQReply();

	QVariant data() const;
	void setData(const QVariant &data);
	
signals:
	void received(const Jreen::IQ &iq);
	
protected:
    explicit IQReply(Client *client);
	
	friend class Jreen::ClientPrivate;
	QScopedPointer<IQReplyPrivate> d_ptr;
};
}

#endif // IQREPLY_H
