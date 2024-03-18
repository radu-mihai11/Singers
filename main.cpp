#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
//using std::string;

class ScreenIcon{
private:
    std::string name;
    float pozX, pozY;
    bool currentState=0;

public:
    ScreenIcon() = default;
    ScreenIcon(const std::string& name, float pozX, float pozY):name(name), pozX(pozX), pozY(pozY){}
    ScreenIcon(const ScreenIcon &obj){
        this->name = obj.name;
        this->pozX = obj.pozX;
        this->pozY = obj.pozY;
        this->currentState = obj.currentState;
    }

    ~ScreenIcon() = default;

    float getPozX() const;
    void setPozX(float pozX);
    float getPozY() const;
    void setPozY(float pozY);
    bool getCurrentState() const;
    void setCurrentState(bool currentState);
    const std::string &getName() const;
    void setName(const std::string &name);

    void afisare();
    void click();
    void setColor() const;
    void resetColor() const;
    void displayIcons(const std::vector<ScreenIcon>& objects) const;


    ScreenIcon &operator=(const ScreenIcon &screenIcon){
        this->name = screenIcon.name;
        this->pozX = screenIcon.pozX;
        this->pozY = screenIcon.pozY;
        this->currentState = screenIcon.currentState;
        return *this;

    }

    friend std::ostream &operator<<(std::ostream &out, const ScreenIcon &screenIcon) {
        out << screenIcon.name <<std::endl << "Current state:"<< screenIcon.currentState << " pozX: " << screenIcon.pozX << " pozY: " << screenIcon.pozY<<std::endl;
        return out;
    }
};

float ScreenIcon::getPozX() const {return pozX;}
void ScreenIcon::setPozX(float pozX) {this->pozX = pozX;}
float ScreenIcon::getPozY() const {return pozY;}
void ScreenIcon::setPozY(float pozY) {this->pozY = pozY;}
bool ScreenIcon::getCurrentState() const {return currentState;}
void ScreenIcon::setCurrentState(bool currentState) {this->currentState = currentState;}
const std::string &ScreenIcon::getName() const {return name;}
void ScreenIcon::setName(const std::string &name) {this->name = name;}

void ScreenIcon::afisare(){std::cout<< name <<std::endl <<"x:"<<pozX<<std::endl<<"y:"<<pozY<<std::endl<<"Current state:"<<currentState<<std::endl;}
void ScreenIcon::click(){currentState = !currentState;}
void ScreenIcon::setColor() const {std::cout << "\033[32m";}
void ScreenIcon::resetColor() const {std::cout << "\033[0m";}
void ScreenIcon::displayIcons(const std::vector<ScreenIcon>& icons) const
{
    for (int i = 0; i < icons.size(); ++i) {
        std::cout << i + 1 << ". " <<icons[i].getName();
        if (icons[i].getCurrentState()) {
            icons[i].setColor(); // Set color to green for active objects
            std::cout << " (Active)";
            icons[i].resetColor(); // Reset color to default after displaying "Active"
        }
        std::cout << "\n";
    }
}

class UserInput{
private:
    std::string userName;

public:

    UserInput() = default;
    UserInput(const std::string &userName): userName(userName){}
    ~UserInput() = default;

    const std::string &getUserName() const;
    void setUserName(const std::string &userName);

    void processInput(std::vector<ScreenIcon>& screenIcons);

    friend std::ostream &operator<<(std::ostream &out, const UserInput &userInput) {
        out <<"Hi "<< userInput.userName <<"!" <<std::endl;
        return out;
    }
};

const std::string &UserInput::getUserName() const {return userName;}
void UserInput::setUserName(const std::string &userName) {this->userName = userName;}

void UserInput::processInput(std::vector<ScreenIcon>& screenIcons){

    while (true) {

        std::cout << "Icons:\n";
        screenIcons[0].displayIcons(screenIcons);

        std::cout << "Enter the index of an icon to activate it (1-" << screenIcons.size() << "), or 'q' to quit: ";

        char i = _getch();
        if (i == 'q') {
            break;
        }
        else
        if (i >= '1' && i <= ('0' + screenIcons.size())) {
            int j = i - '1';
            screenIcons[j].click();
        }
        else{
            std::cout<<std::endl<<"Invalid Input, try again!"<<std::endl;
        }

        system("cls");
    }
}

class Sound {
private:
    std::string soundFile;

public:
    Sound(const std::string& soundFile) : soundFile(soundFile) {}


    friend std::ostream &operator<<(std::ostream &out, const Sound &sound) {
        out << sound.soundFile <<std::endl;
        return out;
    }

    const std::string &getSoundFile() const {return soundFile;}
    void setSoundFile(const std::string &soundFile) {this->soundFile = soundFile;}
};


int main(){

    UserInput user;
    std::string userName;
    int valueIcons;

    std::cout<<"Hi! What's your name?"<<std::endl;
    std::cin>> userName;
    user.setUserName(userName);
    std::cout<<"Hi "<<user.getUserName()<<std::endl<<"How many icons will there be?"<<std::endl;
    std::cin>>valueIcons;

    std::vector<ScreenIcon> screenIcons;
    for(int i=0; i<valueIcons; i++){
        std::string tempName;
        float tempPozX, tempPozY;
        std::cin >> tempName>>tempPozX>>tempPozY;
//        ScreenIcon tempScreenIcon(tempName, tempPozX, tempPozY);
        screenIcons.emplace_back(tempName, tempPozX, tempPozY);
    }

    user.processInput(screenIcons);


    return 0;
}
