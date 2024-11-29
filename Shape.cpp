#include "Shape.h"

// Constructor
Shape::Shape(int id, const QPoint& position)
    : id(id), position(position), pen(Qt::black, 1), brush(Qt::NoBrush) {}

// Getters
int Shape::getId() const {
    return id;
}

const QPoint& Shape::getPosition() const {
    return position;
}

const QPen& Shape::getPen() const {
    return pen;
}

const QBrush& Shape::getBrush() const {
    return brush;
}

// Setters
void Shape::setPosition(const QPoint& position) {
    this->position = position;
}

void Shape::setPen(const QPen& pen) {
    this->pen = pen;
}

void Shape::setBrush(const QBrush& brush) {
    this->brush = brush;
}

std::string Shape::penStyleToString(Qt::PenStyle style) const {
    switch (style) {
    case Qt::NoPen: return "NoPen";
    case Qt::SolidLine: return "SolidLine";
    case Qt::DashLine: return "DashLine";
    case Qt::DotLine: return "DotLine";
    case Qt::DashDotLine: return "DashDotLine";
    case Qt::DashDotDotLine: return "DashDotDotLine";
    case Qt::CustomDashLine: return "CustomDashLine";
    default: return "Unknown";
    }
}

Qt::PenStyle Shape::stringToPenStyle(const std::string& style) {
    if (style == "NoPen") return Qt::NoPen;
    if (style == "SolidLine") return Qt::SolidLine;
    if (style == "DashLine") return Qt::DashLine;
    if (style == "DotLine") return Qt::DotLine;
    if (style == "DashDotLine") return Qt::DashDotLine;
    if (style == "DashDotDotLine") return Qt::DashDotDotLine;
    if (style == "CustomDashLine") return Qt::CustomDashLine;
    return Qt::SolidLine;
}


std::string Shape::penCapStyleToString(Qt::PenCapStyle capStyle) const {
    switch (capStyle) {
    case Qt::FlatCap: return "FlatCap";
    case Qt::SquareCap: return "SquareCap";
    case Qt::RoundCap: return "RoundCap";
    default: return "Unknown";
    }
}

Qt::PenCapStyle Shape::stringToPenCapStyle(const std::string& style) {
    if (style == "FlatCap") return Qt::FlatCap;
    if (style == "SquareCap") return Qt::SquareCap;
    if (style == "RoundCap") return Qt::RoundCap;
    return Qt::FlatCap;
}


std::string Shape::penJoinStyleToString(Qt::PenJoinStyle joinStyle) const {
    switch (joinStyle) {
    case Qt::MiterJoin: return "MiterJoin";
    case Qt::BevelJoin: return "BevelJoin";
    case Qt::RoundJoin: return "RoundJoin";
    case Qt::SvgMiterJoin: return "SvgMiterJoin";
    default: return "Unknown";
    }
}

Qt::PenJoinStyle Shape::stringToPenJoinStyle(const std::string& style) {
    if (style == "MiterJoin") return Qt::MiterJoin;
    if (style == "BevelJoin") return Qt::BevelJoin;
    if (style == "RoundJoin") return Qt::RoundJoin;
    if (style == "SvgMiterJoin") return Qt::SvgMiterJoin;
    return Qt::MiterJoin;
}

std::string Shape::brushStyleToString(Qt::BrushStyle brushStyle) const {
    switch (brushStyle) {
    case Qt::SolidPattern: return "SolidPattern";
    case Qt::Dense1Pattern: return "Dense1Pattern";
    case Qt::Dense2Pattern: return "Dense2Pattern";
    case Qt::Dense3Pattern: return "Dense3Pattern";
    case Qt::Dense4Pattern: return "Dense4Pattern";
    case Qt::Dense5Pattern: return "Dense5Pattern";
    case Qt::Dense6Pattern: return "Dense6Pattern";
    case Qt::Dense7Pattern: return "Dense7Pattern";
    case Qt::HorPattern: return "HorPattern";
    case Qt::VerPattern: return "VerPattern";
    case Qt::CrossPattern: return "CrossPattern";
    case Qt::BDiagPattern: return "BDiagPattern";
    case Qt::FDiagPattern: return "FDiagPattern";
    case Qt::DiagCrossPattern: return "DiagCrossPattern";
    case Qt::LinearGradientPattern: return "LinearGradientPattern";
    case Qt::RadialGradientPattern: return "RadialGradientPattern";
    case Qt::ConicalGradientPattern: return "ConicalGradientPattern";
    case Qt::TexturePattern: return "TexturePattern";
    default: return "Unknown";
    }
}


