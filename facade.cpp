/*
    Facade Pattern
    여러 서브 모듈로 구성된 시스템을 하나의 창구로 간단하게 사용하는 디자인 패턴
*/

#include <iostream>

// SRP에 따라 각각 클래스 분류

class UserCreater {
public:
    void createUser() {
        // Save User Logic ...
    }
};

class UserDeleter {
public:
    void deleteUser(int userId) {
        // Delete User Logic ...
    }
};

class UserUpdater {
public:
    void updateUser(int userId) {
        // Update User Logic ...
    }
};

// UserController에서 위의 서브 모듈 제어

class UserControllerFacade {
private:
    UserCreater userCreater;
    UserDeleter userDeleter;
    UserUpdater userUpdater;
public:
    UserControllerFacade() {
        userCreater = UserCreater();
        userDeleter = UserDeleter();
        userUpdater = UserUpdater();
    }

    void createUser() {
        userCreater.createUser();
    };

    void deleteUser(int userId) {
        userDeleter.deleteUser(userId);
    };

    void updateUser(int userId) {
        userUpdater.updateUser(userId);
    };
};

// 클라이언트 쪽에서는 UserController만을 이용

int main(void)
{
    UserControllerFacade userController = UserControllerFacade();

    userController.createUser();

    return 0;
};