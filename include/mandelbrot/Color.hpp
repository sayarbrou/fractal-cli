#ifndef COLOR_DOT_HPP
#define COLOR_DOT_HPP

#include <string>

class Color {
public:
    Color();
    
    Color(const int);
    Color(const int, const int, const int);
    
    Color(const float);
    Color(const float, const float, const float);

    float getR() const;
    float getG() const;
    float getB() const;

    Color getRGB() const; // copy

    void setR(const int);
    void setG(const int);
    void setB(const int);

    void setR(const float);
    void setG(const float);
    void setB(const float);

    Color getGammaCorrected() const;
    void gammaCorrect();

    std::string toString() const;

    // operators

    Color operator+(Color const&) const;
    Color operator-(Color const&) const;
    Color operator*(Color const&) const;
    Color operator/(Color const&) const;

    Color operator+(const float) const;
    Color operator-(const float) const;
    Color operator*(const float) const;
    Color operator/(const float) const;

    Color operator-() const; // negate color (0.0-color)
    Color operator!() const; // complement (1.0-color)

    void operator+=(Color const&);
    void operator-=(Color const&);
    void operator*=(Color const&);
    void operator/=(Color const&);

private:
    float r, g, b;

};

Color operator+(const float, Color const&);
Color operator-(const float, Color const&);
Color operator*(const float, Color const&);
Color operator/(const float, Color const&);

#endif
