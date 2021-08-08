#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <time.h>
#include<iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace sf;

struct dela // Настя + Лена
{
    string nazvanie = " ";
    string prioritet = "~";
    string opisanie = "None";
    int chislo = 0;
    int mesyac = 0;
    int god = 0;
    int chas = 0;
    int min = 0;
};


void print() { // Кеп 
    system("cls");
    cout << "1 - create\n2-edit\n3-delete\n4-sorting\n5-search\n";
}


void sort(dela obj[], const int kd) { // Кеп
    dela time_obj;
    for (int i = 0; i < kd; i++) {
        if (!obj[i].god) {
            for (int j = i; j < kd - 1; j++) {
                time_obj = obj[j];
                obj[j] = obj[j + 1];
                obj[j + 1] = time_obj;
            }
        }
    }
}


int last(dela obj[], const int kd) { // Кеп
    sort(obj, kd);
    for (int i = 0; i < kd; i++) {
        if (obj[i].god == 0) {
            return i;
        }
    }
}


void edit(dela obj[], const int kd) { //Арсений и немного Кеп
    int i;
    cout << "Number:", cin >> i;
    i--;
    cin.ignore(1, '\n');
    while (true) {

        string time_string;
        int x = 0;
        cout << "\nEnter the name of your case: ", getline(cin, time_string);
        cout << "\nEnter the priority of your case: ", getline(cin, obj[i].prioritet);
        cout << "\nEnter a description of your case: ", getline(cin, obj[i].opisanie);
        cout << "\nEnter case date year.month.number: ", cin >> obj[i].god, cin.ignore(1, '.'), cin >> obj[i].mesyac, cin.ignore(1, '.'), cin >> obj[i].chislo;
        cout << "\nTime hour.min: ", cin >> obj[i].chas, cin.ignore(1, '.'), cin >> obj[i].min;
        cin.ignore(1, '\n');
        for (int j = 0; j < kd; j++) {
            if (time_string == obj[j].nazvanie) {
                x = 1;
            }
        }
        if (x == 1) {
            cout << "This name already exists, please enter a new one." << endl;
            continue;
        }
        obj[i].nazvanie = time_string;
        break;
    }
}


void set(dela obj[], const int kd) // Настя + Лена 
{
    while(true){
        int i = last(obj, kd);
        string time_string;
        int x = 0;
        cout << "\nEnter the name of your case: ", getline(cin, time_string);
        cout << "\nEnter the priority of your case: ", getline(cin, obj[i].prioritet);
        cout << "\nEnter a description of your case: ", getline(cin, obj[i].opisanie);
        cout << "\nEnter case date year.month.number: ", cin >> obj[i].god, cin.ignore(1, '.'), cin >> obj[i].mesyac, cin.ignore(1, '.'), cin >> obj[i].chislo;
        cout << "\nTime hour.min: ", cin >> obj[i].chas, cin.ignore(1, '.'), cin >> obj[i].min;
        cin.ignore(1, '\n');
        for (int j = 0; j < kd; j++) {
            if (time_string == obj[j].nazvanie) {
                x = 1;
            }
        }
        if (x == 1) {
            cout << "This name already exists, please enter a new one." << endl;
            continue;
        }
        obj[i].nazvanie = time_string;
        break;
    }
}


void __delete__(dela obj[]) { // Кеп
    int i;
    cout << "Number (delete):", cin >> i;
    cin.ignore(1, '\n');
    i--;
    obj[i].chas = 0;
    obj[i].chislo = 0;
    obj[i].god = 0;
    obj[i].mesyac = 0;
    obj[i].min = 0;
    obj[i].nazvanie = " ";
    obj[i].opisanie = "None";
    obj[i].prioritet = "~";
}


void __sorrt__(dela obj[], const int kd) { // Арсений + Богдан 
    int say;
    dela timeik;
    cout << "input sort(1/2):", cin >> say;
    cin.ignore(1, '\n');
    if (say == 1) {
        for (int i = 0; i < kd; i++) {
            for (int j = 0; j < kd - i - 1; j++) {
                if (obj[j].prioritet[0] > obj[j + 1].prioritet[0]) {
                    timeik = obj[j + 1];
                    obj[j + 1] = obj[j];
                    obj[j] = timeik;
                }
            }
        }
    }
    else if (say == 2) {
        for (int i = 0; i < kd; i++) {
            for (int j = 0; j < kd - i - 1; j++) {
                if (((obj[j].god * 525600) + (obj[j].mesyac * 43800) + (obj[j].chislo * 1440) + (obj[j].chas * 60) + obj[j].min) > ((obj[j + 1].god * 525600) + (obj[j + 1].mesyac * 43800) + (obj[j + 1].chislo * 1440) + (obj[j + 1].chas * 60) + obj[j + 1].min) && obj[j].god != 0 && obj[j+1].god) {
                    timeik = obj[j + 1];
                    obj[j + 1] = obj[j];
                    obj[j] = timeik;
                }
            }
        }
    }
}

int search(dela obj[], const int kd) { // Кеп
    string say;
    cout << "\nEnter name:";
    getline(cin, say);
    cin.ignore(1, '\n');
    for (int i = 0; i < kd; i++) {
        if (obj[i].nazvanie == say) {
            return i;
        }
    }
    cout << "Not found;";
}

int main()
{
    Music music;
    music.openFromFile("Для игры/main-menu-2.ogg");
    //music.play();
    int i = 0;
    Font font;
    font.loadFromFile("DroidSans.ttf");
    Text text;
    text.setFont(font);
    const int kd = 20;
    dela delishki[kd] = {};
    int say;
    RenderWindow window(VideoMode(600, 600), "Game");
    print();
	while (window.isOpen())// Артем и Кеп
	{
		Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Num1) {
                    set(delishki, kd);
                    print();
                }
                else if (event.key.code == Keyboard::Num2) {
                    edit(delishki, kd);
                    sort(delishki, kd);
                    print();
                }
                else if (event.key.code == Keyboard::Num3) {
                    __delete__(delishki);
                    sort(delishki, kd);
                    print();
                }
                else if (event.key.code == Keyboard::Num4) {
                    __sorrt__(delishki, kd);
                    
                    print();
                }
                else if (event.key.code == Keyboard::Num5) {
                    i = search(delishki, kd);
                    print();
                }
                else if (event.key.code == Keyboard::PageDown && i < kd-1) {
                    i++;
                }
                else if (event.key.code == Keyboard::PageUp && i > 0) {
                    i--;
                }
            }

        }
        window.clear();
		// Отрисовка окнa
            text.setString(to_string(i+1) + ". Name:" + delishki[i].nazvanie + '\n' + "Prioritet:" + delishki[i].prioritet + '\n' + delishki[i].opisanie + "\nTime:" + to_string(delishki[i].chas) + ":" + to_string(delishki[i].min) + "\nDate:" + to_string(delishki[i].god) + "/" + to_string(delishki[i].mesyac) + "/" + to_string(delishki[i].chislo));
            text.setCharacterSize(24);
            text.setFillColor(Color::White);
            window.clear();
            window.draw(text);
		
		window.display();
	}
	return 0;
}
