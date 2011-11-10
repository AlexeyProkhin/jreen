#ifndef SOFTWAREVERSIONFACTORY_H
#define SOFTWAREVERSIONFACTORY_H
#include "softwareversion.h"

namespace Jreen {

class SoftwareVersionFactoryPrivate;
class SoftwareVersionFactory : public PayloadFactory<SoftwareVersion>
{
	Q_DECLARE_PRIVATE(SoftwareVersionFactory)
public:
	SoftwareVersionFactory();
	virtual ~SoftwareVersionFactory();
	QStringList features() const;
	bool canParse(const QStringRef &name, const QStringRef &uri, const QXmlStreamAttributes &attributes);
	void handleStartElement(const QStringRef &name, const QStringRef &uri, const QXmlStreamAttributes &attributes);
	void handleEndElement(const QStringRef &name, const QStringRef &uri);
	void handleCharacterData(const QStringRef &text);
	void serialize(Payload *extension, QXmlStreamWriter *writer);
	Payload::Ptr createPayload();
private:
	QScopedPointer<SoftwareVersionFactoryPrivate> d_ptr;
};

} // namespace Jreen

#endif // SOFTWAREVERSIONFACTORY_H