//
//  rational.cpp
//  RationalNumbers
//
/*
 * File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include "rational.hpp"
#include <cstdlib>
#include "error.h"
#include "rational.hpp"
#include "strlib.h"

/* Function prototypes */
int gcd(int x, int y);

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Rational class. The default
 * constructor creates a Rational with a zero value, the one-argument
 * form converts an integer to a Rational, and the two-argument form
 * allows specifying a fraction. The constructors ensure that
 * the following invariants are maintained:
 *
 * 1. The fraction is always reduced to lowest terms.
 * 2. The denominator is always positive.
 * 3. Zero is always represented as 0/1.
 */

Rational::Rational() {
    num = 0;
    den = 1;
}

Rational::Rational(int n) {
    num = n;
    den = 1;
}

Rational::Rational(int x, int y) {
    if (y == 0) error("Rational: Division by zero.");
    if (x == 0) {
        num = 0;
        den = 1;
    } else {
        int g = gcd(abs(x), abs(y));
        num = x / g;
        den = abs(y) / g;
        if (y < 0) num = -num;
    }
}

/* Implementation of toString and the << operator */
std::string Rational::toString() {
    if (den == 1) {
        return integerToString(num);
    } else {
        return integerToString(num) + "/" + integerToString(den);
    }
}

std::ostream & operator<<(std::ostream & os, Rational rat) {
    return os << rat.toString();
}

/*
 * Implementation notes: arithmetic operators
 * ------------------------------------------
 * The implementation of the operators follows directly from the definitions.
 */

Rational operator+(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den + r1.den * r2.num, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2) {
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den, r1.den * r2.num);
}

/* Relational operators */
bool operator==(Rational r1, Rational r2) {
    return r1.num == r2.num && r1.den == r2.den;
}

bool operator!=(Rational r1, Rational r2) {
    return !(r1 == r2);
}

bool operator>(Rational r1, Rational r2) {
    int lcm = r1.den * r2.den;
    int r1Num = (lcm / r1.den) * r1.num;
    int r2Num = (lcm / r2.den) * r2.num;
    return r1Num > r2Num;
}

bool operator<(Rational r1, Rational r2) {
    return !(r1 > r2);
}

bool operator<=(Rational r1, Rational r2) {
    return r1 < r2 || r1 == r2;
}

bool operator>=(Rational r1, Rational r2) {
    return r1 > r2 || r1 == r2;
}

/* Shorthand Assignment Operators*/
Rational & operator+=(Rational & r1, Rational r2) {
    return r1 = r1 + r2;
}

Rational & operator-=(Rational & r1, Rational r2) {
    return r1 = r1 - r2;
}

Rational & operator*=(Rational & r1, Rational r2) {
    return r1 = r1 * r2;
}

Rational & operator/=(Rational & r1, Rational r2) {
    return r1 = r1 / r2;
}

Rational operator++(Rational & r1, int) {
    Rational old = r1;
    r1 = r1 + 1;
    return old;
}

Rational operator--(Rational & r1, int) {
    Rational old = r1;
    r1 = r1 - 1;
    return old;
}

Rational operator++(Rational & r1) {
    return r1 = r1 + 1;
}

Rational operator--(Rational & r1) {
    return r1 = r1 - 1;
}

/*
 * Implementation notes: gcd
 * -------------------------
 * This implementation uses Euclid's algorithm to calculate the
 * greatest common divisor.
 */

int gcd(int x, int y) {
    int r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}








