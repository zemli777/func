#include "wood.h"

int swap(string s) {
int k = 0;
for (int i = 0; i < s.length(); i++) {
k = k * 10 + s[i] - '0';

}
return k;
}

void wood3::TransformToWood(string expression) {
    //ax+b
    point* itm = new point;
    itm->data = expression[expression.find('x') + 1];
    point* itm1 = new point;
    itm1->parent = itm;
    int k = 0;
    k = expression.find('x') + 2;
    while (k < expression.length()) {
        itm1->data += expression[k];
        k++;
    }
    itm->right = itm1;

    point* itm2 = new point;
    itm2->parent = itm;
    itm2->data = expression[expression.find('x') - 1];
    itm->left = itm2;
    point* itm3 = new point;
    itm3->parent = itm2;
    itm3->data = expression[expression.find('x')];
    itm2->right = itm3;
    point* itm4 = new point;
    itm4->parent = itm2;
    k = 0;
    while (expression[k + 1] != 'x') {
        itm4->data += expression[k];
        k++;
    }
    itm2->left = itm4;
    int g = 0;
    First3 = itm;
};

void wood2::TransformToWood(string expression) {
    //(ax^2+bx+c)
    point* itm = new point;
    itm->data = "";
    point* itm2 = new point;
    int find = expression.find('^');
    itm2->data = expression[find - 2];
    itm2->parent = itm;
    itm->left = itm2;
    point* itm3 = new point;
    int k = 0;
    while (k < (find - 2)) {
        itm3->data += expression[k];
        k++;
    }
    itm3->parent = itm2;
    itm2->left = itm3;
    point* itm4 = new point;
    itm4->data = '*';
    itm4->parent = itm2;
    itm2->right = itm4;
    point* itm5 = new point;
    itm5->data = expression[find - 1];
    itm5->parent = itm4;
    itm4->left = itm5;
    itm4->right = itm5;
    point* itm6 = new point;
    point* itm7 = new point;
    k = find;
    k++;
    k++;
    itm->data = expression[k];
    k++;
    while ('0' <= expression[k] && expression[k] <= '9') {
        itm6->data += expression[k];
        k++;
    }
    itm7->data = expression[k];
    k++;
    point* itm8 = new point;
    itm8->data = expression[k];
    k++;
    itm8->parent = itm7;
    itm7->right = itm8;
    itm7->left = itm6;
    itm6->parent = itm7;
    point* itm9 = new point;
    itm9->data = expression[k];
    k++;
    itm7->parent = itm9;
    itm9->left = itm7;
    point* itm10 = new point;
    while (k < expression.length()) {
        itm10->data += expression[k];
        k++;
    }
    itm10->parent = itm9;
    itm9->right = itm10;
    itm9->parent = itm;
    itm->right = itm9;
    First2 = itm;
};
void wood1::TransformToWood(string expression) {
    //(ax+b)/(cx+d)
    point* itm = new point;
    int find = expression.find('/');
    itm->data = expression[find];
    First1 = itm;
    point* itm2 = new point;
    int k = find-2;
    while ('0' <= expression[k] && expression[k] <= '9') k--;
    itm2->data = expression[k];
    k++;
    itm2->parent = itm;
    itm->left = itm2;
    point* itm3 = new point;
    while ('0' <= expression[k] && expression[k] <= '9') {
        itm3->data += expression[k];
        k++;
    };
    itm3->parent = itm2;
    itm2->right = itm3;
    point* itm4 = new point;
    k = expression.find('*');
    itm4->data = expression[k];
    itm4->parent = itm2;
    itm2->left = itm4;
    point* itm5 = new point;
    k = 1;
    while ('0' <= expression[k] && expression[k] <= '9') {
        itm5->data += expression[k];
        k++;
    }
    itm5->parent = itm4;
    itm4->left = itm5;
    point* itm6 = new point;
    k = expression.find('*')+1;
    itm6->data = expression[k];
    itm6->parent = itm4;
    itm4->right = itm6;
    point* itm8 = new point;
    k = expression.length() - 2;
    while ('0' <= expression[k] && expression[k] <= '9') {
        itm8->data += expression[k];
        k--;
    }
    point* itm7 = new point;
    itm7->data = expression[k];
    itm7->parent = itm;
    itm->right = itm7;
    itm7->right = itm8;
    itm8->parent = itm7;
    point* itm9 = new point;
    k--;
    k--;
    itm9->data = expression[k];
    itm9->parent = itm7;
    itm7->left = itm9;
    point* itm11 = new point;
    k++;
    itm11->data = expression[k];
    itm11->parent = itm9;
    itm9->right = itm11;
    point* itm10 = new point;
    k = find + 2;
    while ('0' <= expression[k] && expression[k] <= '9') {
        itm10->data += expression[k];
        k++;
    }
    itm10->parent = itm9;
    itm9->left = itm10;
};

double wood3::value(point* FirstEl, int i) {
    int k = 0;
    if (FirstEl->data == "+") k = swap(FirstEl->left->left->data) * i  + swap(FirstEl->right->data);
    else k = swap(FirstEl->left->left->data) * i - swap(FirstEl->right->data);
    return k;
};

double wood2::value(point* FirstEl, int i) {
    int k = 0;
    k = swap(FirstEl->left->left->data) * i * i;
    if (FirstEl->data == "+") k += swap(FirstEl->right->left->left->data) * i;
    else k -= swap(FirstEl->right->left->left->data) * i;
    if (FirstEl->right->data == "+") k += swap(FirstEl->right->right->data);
    else k -= swap(FirstEl->right->right->data);
    return k;
};

double wood1::value(point* FirstEl, int i) {
    double k = NULL;
    double k1 = swap(First1->left->left->left->data) * i;
    if (First1->left->data == "+") k1 += swap(First1->left->right->data); 
    else k1 -= swap(First1->left->right->data);;
    double k2 = swap(First1->right->left->left->data) * i;
    if (First1->right->data == "+") k2 += swap(First1->right->right->data);
    else k2 -= swap(First1->right->right->data);
    if (k2 != 0) k = k1 / k2; else k = 999999999;
    return k;

}

void wood3::PrintWood() {
    cout << "y= " << First3->left->left->data << First3->left->data << First3->left->right->data << First3->data <<First3->right->data << endl;
};

void wood2::PrintWood() {
    cout << "y= " << First2->left->left->data << First2->left->data << First2->left->right->left->data << First2->left->right->data 
    << First2->left->right->right->data << First2->data << First2->right->left->left->data << First2->right->left->data 
    << First2->right->left->right->data << First2->right->data << First2->right->right->data;
};
void wood1::PrintWood() {
    cout <<'('<< First1->left->left->left->data << First1->left->left->data << First1->left->left->right->data << 
    First1->left->data << First1->left->right->data <<
    ")/("<<First1->right->left->left->data << First1->right->left->data << First1->right->left->right->data 
    << First1->right->data << First1->right->right->data<<')';
}

double wood::FindExtremMax(point* point, int i, int j) {
    double k = value(point, i);
    for (i; i <= j; i++) {
        if (value(point, i) !=NULL) if (k < value(point, i)) k = value(point, i);
    };
    return k;
};
double wood::FindExtremMin(point* point, int i, int j) {
    double k = value(point, i);
    for (i; i <= j; i++) {
        if (value(point, i) != NULL) if (k > value(point, i)) k = value(point, i);
    };
    return k;
};
