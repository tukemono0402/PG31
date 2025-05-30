#include <cstdio>
using namespace std;

class Animal { // 動物クラス
public:
    virtual void sound() const = 0;  // 純粋仮想関数
};

class Dog : public Animal { // 犬クラス
public:
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};

class Cat : public Animal { // 猫クラス
public:
    void sound() const override {
        printf("ネコ鳴き声:ニャー\n");
    }
};

int main() {
    Animal* animal1 = new Dog(); // 犬クラス
    Animal* animal2 = new Cat(); // 猫クラス

    animal1->sound();
    animal2->sound();

    delete animal1;
    delete animal2;

    return 0;
}