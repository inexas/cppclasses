#include <iostream>
#include <list>

using namespace std;

class Obstacle {
public:
    virtual void draw() const = 0;

protected:
    Obstacle(char name, int id) : name(name), id(id) {
        cout << "Obstacle ctor" << endl;
    }

    char name;
    int id;

private:
};

class Water : public Obstacle {
public:
    // public ctor
    Water(char name, int id) : Obstacle(name, id) {
        cout << "Water ctor" << endl;
    }

    // concrete class must implement draw()
    void draw() const override { cout << "Water.draw(): " << name << id << endl; }

private:
};

class LivingEntity : public Obstacle {
public:
    void draw() const override { cout << "LivingEntity.draw(): " << name << id << endl; }

protected:
    // Abstract class: protected ctor, no draw
    LivingEntity(char name, int id) : Obstacle(name, id) {
        cout << "LivingEntity ctor" << endl;
    }

private:
};

class Bush : public LivingEntity {
public:
    Bush(char name, int id) : LivingEntity(name, id) {
        cout << "Bush ctor" << endl;
    }

    void draw() const override { cout << "Bush.draw(): " << name << id << endl; }

protected:
private:
};

class Animal : public LivingEntity {
public:
protected :
    // Abstract class: protected ctor, no draw
    explicit Animal(char name, int id) : LivingEntity(name, id) {
        cout << "Animal ctor" << endl;
    }

private :
};

class Buffalo : public Animal {
public:
    Buffalo(char name, int id) : Animal(name, id) {
        cout << "Buffalo ctor" << endl;
    }

    void draw() const override { cout << "Buffalo.draw(): " << name << id << endl; }

protected:

private:
};

int main() {
    list<LivingEntity *> etres;
    int id = 1;

    Water water = Water('w', id++);
    water.draw();
    cout << endl;

    // LivingEntity livingEntity = LivingEntity('l', id++); ERROR: Abstract class, ditto Animal
    Bush bush = Bush('g', id++);
    bush.draw();
    etres.push_back(&bush);
    cout << endl;

    Buffalo buffalo = Buffalo('b', id++);
    buffalo.draw();
    etres.push_back(&buffalo);
    cout << endl;

    cout << "Size of etres: " << etres.size() << endl;
    for (LivingEntity* etre: etres) {
        ((LivingEntity*)etre)->draw();
    }
}
