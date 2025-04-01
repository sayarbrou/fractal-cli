#include "mandelbrot/Color.hpp"

#include <string>
#include <sstream>
#include <cmath>

Color::Color() {
    r = g = b = 0.0f;
}

Color::Color(const int val) {
    r = g = b = static_cast<float>(val);
}

Color::Color(const int vr, const int vg, const int vb) {
    r = static_cast<float>(vr) / 255.0f;
    g = static_cast<float>(vg) / 255.0f;
    b = static_cast<float>(vb) / 255.0f;
}

Color::Color(const float val) {
    r = g = b = val;
}

Color::Color(const float vr, const float vg, const float vb) {
    r = vr;
    g = vg;
    b = vb;
}

float Color::getR() const {
    return r;
}

float Color::getG() const {
    return g;
}

float Color::getB() const {
    return b;
}

Color Color::getRGB() const {
    return Color(r, g, b);
}

void Color::setR(const int val) {
    r = static_cast<float>(val) / 255.0f;
}

void Color::setG(const int val) {
    g = static_cast<float>(val) / 255.0f;
}

void Color::setB(const int val) {
    b = static_cast<float>(val) / 255.0f;
}

void Color::setR(const float val) {
    r = val;
}

void Color::setG(const float val) {
    g = val;
}

void Color::setB(const float val) {
    b = val;
}

Color Color::getGammaCorrected() const {
    return Color(
        std::powf(r, 0.4545f),
        std::powf(g, 0.4545f),
        std::powf(b, 0.4545f)
    );
}

void Color::gammaCorrect() {
    r = std::powf(r, 0.4545f);
    g = std::powf(g, 0.4545f);
    b = std::powf(b, 0.4545f);
}

std::string Color::toString() const {
    std::stringstream ss;
    ss << "rgb("
        << static_cast<int>(r*255.999) << ", "
        << static_cast<int>(g*255.999) << ", "
        << static_cast<int>(b*255.999) << ")";
    return ss.str();
}

Color Color::operator+(Color const& c) const {
    return Color(
        r + c.getR(),
        g + c.getG(),
        b + c.getB()
    );
}

Color Color::operator-(Color const& c) const {
    return Color(
        r - c.getR(),
        g - c.getG(),
        b - c.getB()
    );
}

Color Color::operator*(Color const& c) const {
    return Color(
        r * c.getR(),
        g * c.getG(),
        b * c.getB()
    );
}

Color Color::operator/(Color const& c) const {
    return Color(
        r / c.getR(),
        g / c.getG(),
        b / c.getB()
    );
}


Color Color::operator+(const float c) const {
    return Color(r + c, g + c, b + c);
}

Color Color::operator-(const float c) const {
    return Color(r - c, g - c, b - c);
}

Color Color::operator*(const float c) const {
    return Color(r * c, g * c, b * c);
}

Color Color::operator/(const float c) const {
    return Color(r / c, g / c, b / c);
}

Color Color::operator-() const {
    return Color(-r, -g, -b);
}

Color Color::operator!() const {
    return Color(1.0f-r, 1.0f-g, 1.0f-b);
}

void Color::operator+=(Color const& c) {
    r += c.getR();
    g += c.getG();
    b += c.getB();
}

void Color::operator-=(Color const& c) {
    r -= c.getR();
    g -= c.getG();
    b -= c.getB();
}

void Color::operator*=(Color const& c) {
    r *= c.getR();
    g *= c.getG();
    b *= c.getB();
}

void Color::operator/=(Color const& c) {
    r /= c.getR();
    g /= c.getG();
    b /= c.getB();
}

Color operator+(const float s, Color const& c) {
    return Color(
        s + c.getR(),
        s + c.getG(),
        s + c.getB()
    );
}

Color operator-(const float s, Color const& c) {
    return Color(
        s - c.getR(),
        s - c.getG(),
        s - c.getB()
    );
}

Color operator*(const float s, Color const& c) {
    return Color(
        s * c.getR(),
        s * c.getG(),
        s * c.getB()
    );
}

Color operator/(const float s, Color const& c) {
    return Color(
        s / c.getR(),
        s / c.getG(),
        s / c.getB()
    );
}
