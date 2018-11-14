//
// Created by 姚文锋 on 2018/11/14.
//
#include <iostream>

using namespace std;

// 不同的变化方向(业务和平台)，所以分为两个类
class MachineImp {
public:
    virtual void PlaySound() = 0;

    virtual void DrawShape() = 0;

    virtual void WriteText() = 0;

    virtual void Connect() = 0;

    virtual MachineImp *NewImp() = 0;

    MachineImp() {};
};

class Machine {
private:
    Machine(MachineImp *newImp) {
        this->machineImp = newImp->NewImp();
    };
protected:
    MachineImp *machineImp;//...

public:
    virtual void Login(string username, string password) = 0;

    virtual void SendMessage(string message) = 0;

    virtual void SendPicture(string image) = 0;
};

//平台实现 n
class PCMachineImp : public MachineImp {
public:

    void PlaySound() override {
        //**********
    }

    void DrawShape() override {
        //**********
    }

    void WriteText() override {
        //**********
    }

    void Connect() override {
        //**********
    }

    MachineImp *NewImp() override {
        return new PCMachineImp();
    }
};

class MobileMachineImp : public MachineImp {
public:

    void PlaySound() override {
        //==========
    }

    void DrawShape() override {
        //==========
    }

    void WriteText() override {
        //==========
    }

    void Connect() override {
        //==========
    }
};

//业务抽象 m
//类的数目：1+n+m

class MachineLite : public Machine {

public:

    virtual void Login(string username, string password) {

        machineImp->Connect();
        //........
    }

    virtual void SendMessage(string message) {

        machineImp->WriteText();
        //........
    }

    virtual void SendPicture(string image) {

        machineImp->DrawShape();
        //........
    }
};


class MachinePerfect : public Machine {


public:

    virtual void Login(string username, string password) {

        machineImp->PlaySound();
        //********
        machineImp->Connect();
        //........
    }

    virtual void SendMessage(string message) {

        machineImp->PlaySound();
        //********
        machineImp->WriteText();
        //........
    }

    virtual void SendPicture(string image) {

        machineImp->PlaySound();
        //********
        machineImp->DrawShape();
        //........
    }
};


void Process() {
    //运行时装配
    MachineImp *mImp = new PCMachineImp();
    Machine *m = new Machine(mImp);
}