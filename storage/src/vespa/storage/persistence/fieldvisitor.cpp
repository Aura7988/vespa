// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
// @author Vegard Sjonfjell
#include <vespa/storage/persistence/fieldvisitor.h>

namespace storage {

void FieldVisitor::visitFieldValueNode(const document::select::FieldValueNode & node) {
    _fields.insert(_docType.getField(node.getFieldName()));
}

void FieldVisitor::visitComparison(const document::select::Compare & node) {
    visitBothBranches(node);
}

void FieldVisitor::visitAndBranch(const document::select::And & node) {
    visitBothBranches(node);
}

void FieldVisitor::visitOrBranch(const document::select::Or & node) {
    visitBothBranches(node);
}

void FieldVisitor::visitNotBranch(const document::select::Not & node) {
    node.getChild().visit(*this);
}

} // storage
