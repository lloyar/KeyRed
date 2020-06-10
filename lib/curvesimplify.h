//
// Created by Yang Lee on 2020/5/25.
//

#ifndef CURVESIMPLIFY_H
#define CURVESIMPLIFY_H

/* A C data structure */
typedef struct Point {
    double t, v;
} Point;

typedef struct KeyFrame {
    int index;
    double time, value, leftTangent, rightTangent;
} KeyFrame;

struct KeyFrameNode {
    KeyFrame *key;
    struct KeyFrameNode *prev;
    struct KeyFrameNode *next;
};

extern struct KeyFrameNode *simplify_curve(Point *points, int n);

#endif //CURVESIMPLIFY_H
