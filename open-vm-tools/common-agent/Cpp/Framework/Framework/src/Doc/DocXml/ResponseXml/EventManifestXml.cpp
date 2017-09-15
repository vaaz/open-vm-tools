/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"
#include "EventManifestXml.h"

using namespace Caf;

void EventManifestXml::add(
	const SmartPtrCEventManifestDoc eventManifestDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("EventManifestXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(eventManifestDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string classNamespaceVal = eventManifestDoc->getClassNamespace();
		CAF_CM_VALIDATE_STRING(classNamespaceVal);
		thisXml->addAttribute("classNamespace", classNamespaceVal);

		const std::string classNameVal = eventManifestDoc->getClassName();
		CAF_CM_VALIDATE_STRING(classNameVal);
		thisXml->addAttribute("className", classNameVal);

		const std::string classVersionVal = eventManifestDoc->getClassVersion();
		CAF_CM_VALIDATE_STRING(classVersionVal);
		thisXml->addAttribute("classVersion", classVersionVal);

		const std::string operationNameVal = eventManifestDoc->getOperationName();
		CAF_CM_VALIDATE_STRING(operationNameVal);
		thisXml->addAttribute("operationName", operationNameVal);

		const SmartPtrCAttachmentCollectionDoc attachmentCollectionVal =
			eventManifestDoc->getAttachmentCollection();
		CAF_CM_VALIDATE_SMARTPTR(attachmentCollectionVal);

		const SmartPtrCXmlElement attachmentCollectionXml =
			thisXml->createAndAddElement("attachmentCollection");
		AttachmentCollectionXml::add(attachmentCollectionVal, attachmentCollectionXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCEventManifestDoc EventManifestXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("EventManifestXml", "parse");

	SmartPtrCEventManifestDoc eventManifestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string classNamespaceStrVal =
			thisXml->findRequiredAttribute("classNamespace");
		const std::string classNamespaceVal = classNamespaceStrVal;

		const std::string classNameStrVal =
			thisXml->findRequiredAttribute("className");
		const std::string classNameVal = classNameStrVal;

		const std::string classVersionStrVal =
			thisXml->findRequiredAttribute("classVersion");
		const std::string classVersionVal = classVersionStrVal;

		const std::string operationNameStrVal =
			thisXml->findRequiredAttribute("operationName");
		const std::string operationNameVal = operationNameStrVal;

		const SmartPtrCXmlElement attachmentCollectionXml =
			thisXml->findRequiredChild("attachmentCollection");

		SmartPtrCAttachmentCollectionDoc attachmentCollectionVal;
		if (! attachmentCollectionXml.IsNull()) {
			attachmentCollectionVal = AttachmentCollectionXml::parse(attachmentCollectionXml);
		}

		eventManifestDoc.CreateInstance();
		eventManifestDoc->initialize(
			classNamespaceVal,
			classNameVal,
			classVersionVal,
			operationNameVal,
			attachmentCollectionVal);
	}
	CAF_CM_EXIT;

	return eventManifestDoc;
}
