// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.1415;
const double EPS = 1e-6;


TEST(AllTests, test_1) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}

TEST(AllTests, test_2) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(AllTests, test_3) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 4.0);
}

TEST(AllTests, test_4) {
    Circle c(1.0);
    double newFerence = 10.0;
    c.setFerence(newFerence);
    double expectedRadius = newFerence / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
    EXPECT_NEAR(c.getArea(), PI * expectedRadius * expectedRadius, EPS);
}

TEST(AllTests, test_5) {
    Circle c(1.0);
    double newArea = 50.0;
    c.setArea(newArea);
    double expectedRadius = std::sqrt(newArea / PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * expectedRadius, EPS);
    EXPECT_DOUBLE_EQ(c.getArea(), newArea);
}

TEST(AllTests, test_6) {
    Circle c(3.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_NEAR(f, 2 * PI * r, EPS);
    EXPECT_NEAR(a, PI * r * r, EPS);
}

TEST(AllTests, test_7) {
    Circle c(1.0);
    c.setFerence(20.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_NEAR(f, 2 * PI * r, EPS);
    EXPECT_NEAR(a, PI * r * r, EPS);
}

TEST(AllTests, test_8) {
    Circle c(1.0);
    c.setArea(100.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_NEAR(f, 2 * PI * r, EPS);
    EXPECT_NEAR(a, PI * r * r, EPS);
}

TEST(AllTests, test_9) {
    Circle c(2.0);
    c.setRadius(4.0);
    c.setFerence(30.0);
    c.setArea(200.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_NEAR(a, 200.0, EPS);
    EXPECT_NEAR(r, std::sqrt(200.0 / PI), EPS);
    EXPECT_NEAR(f, 2 * PI * r, EPS);
}

TEST(AllTests, test_10) {
    double r = 1e-10;
    Circle c(r);
    EXPECT_DOUBLE_EQ(c.getRadius(), r);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * r);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * r * r);
}

TEST(AllTests, test_11) {
    double r = 1e10;
    Circle c(r);
    EXPECT_DOUBLE_EQ(c.getRadius(), r);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * r);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * r * r);
}

TEST(AllTests, test_12) {
    Circle c(5.0);
    double oldF = c.getFerence();
    double oldA = c.getArea();
    c.setRadius(5.0);  // тот же радиус
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), oldF);
    EXPECT_DOUBLE_EQ(c.getArea(), oldA);
}

TEST(AllTests, test_13) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(AllTests, test_14) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(AllTests, test_15) {
    Circle c(0);
    c.setRadius(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * (-5.0));
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}

TEST(AllTests, test_16) {
    Circle c(0);
    c.setFerence(-10.0);
    double expectedRadius = -10.0 / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_DOUBLE_EQ(c.getFerence(), -10.0);
    EXPECT_NEAR(c.getArea(), PI * expectedRadius * expectedRadius, EPS);
}

TEST(AllTests, test_17) {
    Circle c(1.0);
    EXPECT_NEAR(c.getArea(), PI, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(AllTests, test_18) {
    Circle c(0);
    double f = 15.0;
    c.setFerence(f);
    double r = c.getRadius();
    c.setRadius(r);
    EXPECT_NEAR(c.getFerence(), f, EPS);
}

TEST(AllTests, test_19) {
    Circle c(0);
    double a = 25.0;
    c.setArea(a);
    double r = c.getRadius();
    c.setRadius(r);
    EXPECT_NEAR(c.getArea(), a, EPS);
}

TEST(AllTests, test_20) {
    double earth_radius_km = 6378.1;
    double gap = ropeGap(earth_radius_km);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, 1e-6);
}

TEST(AllTests, test_21) {
    double r1 = 1.0;
    double r2 = 1000.0;
    double gap1 = ropeGap(r1);
    double gap2 = ropeGap(r2);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap1, expected_gap, 1e-6);
    EXPECT_NEAR(gap2, expected_gap, 1e-6);
}

TEST(AllTests, test_22) {
    double gap = ropeGap(0.0);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, 1e-6);
}

TEST(AllTests, test_23) {
    double earth_radius_m = 1000.0;
    Circle earth(earth_radius_m);
    double new_ference = earth.getFerence() + 0.0;
    Circle new_circle(0);
    new_circle.setFerence(new_ference);
    double gap = new_circle.getRadius() - earth.getRadius();
    EXPECT_NEAR(gap, 0.0, EPS);
}

TEST(AllTests, test_24) {
    double r_km = 1e-9;
    double gap = ropeGap(r_km);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, 1e-6);
}

TEST(AllTests, test_25) {
    double r_km = 1e6;
    double gap = ropeGap(r_km);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, 1e-6);
}

TEST(AllTests, test_26) {
    double pool_r = 3.0;
    double walkway = 1.0;
    double price = 1000.0;
    double expected = PI * (16.0 - 9.0) * price;
    double cost = poolConcreteCost(pool_r, walkway, price);
    EXPECT_NEAR(cost, expected, 1e-3);
}

TEST(AllTests, test_27) {
    double pool_r = 3.0;
    double walkway = 1.0;
    double price = 2000.0;
    double expected = 2 * PI * 4.0 * price;
    double cost = poolFenceCost(pool_r, walkway, price);
    EXPECT_NEAR(cost, expected, 1e-3);
}

TEST(AllTests, test_28) {
    double pool_r = 3.0;
    double walkway = 1.0;
    double concrete_price = 1000.0;
    double fence_price = 2000.0;
    double expected_concrete = PI * 7.0 * concrete_price;
    double expected_fence = 2 * PI * 4.0 * fence_price;
    double expected_total = expected_concrete + expected_fence;
    double total = poolTotalCost(pool_r, walkway, concrete_price, fence_price);
    EXPECT_NEAR(total, expected_total, 1e-3);
}

TEST(AllTests, test_29) {
    double pool_r = 3.0;
    double walkway = 0.0;
    double concrete_price = 1000.0;
    double fence_price = 2000.0;
    double expected_concrete = 0.0;
    double expected_fence = 2 * PI * pool_r * fence_price;
    double expected_total = expected_fence;
    EXPECT_NEAR(poolConcreteCost(pool_r, walkway, concrete_price), expected_concrete, 1e-3);
    EXPECT_NEAR(poolFenceCost(pool_r, walkway, fence_price), expected_fence, 1e-3);
    EXPECT_NEAR(poolTotalCost(pool_r, walkway, concrete_price, fence_price), expected_total, 1e-3);
}

TEST(AllTests, test_30) {
    double pool_r = 0.0;
    double walkway = 2.0;
    double concrete_price = 1000.0;
    double fence_price = 2000.0;
    double expected_concrete = PI * walkway * walkway * concrete_price;
    double expected_fence = 2 * PI * walkway * fence_price;
    EXPECT_NEAR(poolConcreteCost(pool_r, walkway, concrete_price), expected_concrete, 1e-3);
    EXPECT_NEAR(poolFenceCost(pool_r, walkway, fence_price), expected_fence, 1e-3);
}

TEST(AllTests, test_31) {
    double pool_r = 100.0;
    double walkway = 10.0;
    double concrete_price = 1.0;
    double fence_price = 1.0;
    double expected_concrete = PI * (110.0 * 110.0 - 100.0 * 100.0);
    double expected_fence = 2 * PI * 110.0;
    EXPECT_NEAR(poolConcreteCost(pool_r, walkway, concrete_price), expected_concrete, 1e-3);
    EXPECT_NEAR(poolFenceCost(pool_r, walkway, fence_price), expected_fence, 1e-3);
}

TEST(AllTests, test_32) {
    double pool_r = 2.0;
    double walkway = 0.5;
    double price = 1.0;
    double outer_r = pool_r + walkway;
    double expected = PI * (outer_r * outer_r - pool_r * pool_r) * price;
    double cost = poolConcreteCost(pool_r, walkway, price);
    EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(AllTests, test_33) {
    double pool_r = 2.0;
    double walkway = 0.5;
    double price = 1.0;
    double outer_r = pool_r + walkway;
    double expected = 2 * PI * outer_r * price;
    double cost = poolFenceCost(pool_r, walkway, price);
    EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(AllTests, test_34) {
    double pool_r = 2.0;
    double walkway = 0.5;
    double concrete_price = 1.0;
    double fence_price = 1.0;
    double expected_concrete = PI * (2.5 * 2.5 - 4.0);
    double expected_fence = 2 * PI * 2.5;
    double expected_total = expected_concrete + expected_fence;
    double total = poolTotalCost(pool_r, walkway, concrete_price, fence_price);
    EXPECT_NEAR(total, expected_total, 1e-6);
}

TEST(AllTests, test_35) {
    double pool_r = 3.0;
    double walkway = 1.0;
    double concrete_price = 0.0;
    double fence_price = 2000.0;
    double expected_concrete = 0.0;
    double expected_fence = 2 * PI * 4.0 * fence_price;
    double expected_total = expected_fence;
    EXPECT_NEAR(poolConcreteCost(pool_r, walkway, concrete_price), expected_concrete, 1e-3);
    EXPECT_NEAR(poolFenceCost(pool_r, walkway, fence_price), expected_fence, 1e-3);
    EXPECT_NEAR(poolTotalCost(pool_r, walkway, concrete_price, fence_price), expected_total, 1e-3);
}