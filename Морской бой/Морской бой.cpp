#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>

using namespace std;
int J = 0;
int r;
int c;
void CreateField(char** ARR, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ARR[i][j] = '0';
            ARR[0][0] = ' ';
            ARR[1][0] = '1';
            ARR[2][0] = '2';
            ARR[3][0] = '3';
            ARR[4][0] = '4';
            ARR[5][0] = '5';
            ARR[6][0] = '6';
            ARR[7][0] = '7';
            ARR[8][0] = '8';
            ARR[9][0] = '9';
            ARR[10][0] = '1';


            ARR[0][0] = ' ';
            ARR[0][1] = 'A';
            ARR[0][2] = 'B';
            ARR[0][3] = 'C';
            ARR[0][4] = 'D';
            ARR[0][5] = 'E';
            ARR[0][6] = 'F';
            ARR[0][7] = 'G';
            ARR[0][8] = 'H';
            ARR[0][9] = 'F';
            ARR[0][10] = 'I';
        }
    }
}

void M_free(int** ARR_1, int** ARR_2, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] ARR_1[i];
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] ARR_2[i];
    }

    delete[]ARR_1;
    delete[]ARR_2;
    ARR_1 = nullptr;
    ARR_2 = nullptr;


}
void ShowField(char** ARR_1, char** ARR_2, int rows, int cols)
{
    system("cls");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << ARR_1[i][j] << " ";
        cout << "                ";
        for (int j = 0; j < cols; j++)
            cout << ARR_2[i][j] << " ";
        cout << endl;
    }
}

void ShootingComp(int** ARR, int rows, int cols)//легкий уровень сложности  
{
    J = 0;
    srand(time(NULL));
    int R{ 0 };
    int C{ 0 };
    do {
        R = rand() % 10 + 1;
        C = rand() % 10 + 1;
    } while ((ARR[R][C] == 9) || (ARR[R][C] == 0));
    cout << R << " " << C << endl;
    if (ARR[R][C] == 10)
    {
        cout << "мимо" << endl;
        ARR[R][C] = 0;
        J = 0;
    }
    else
    {
        cout << "Есть попадание!" << endl;
        ARR[R][C] = 9;
        J++;
    }
    cout << endl;
    r = R;
    c = C;
}
void ShootingCompComplexity_1(int** ARR, int rows, int cols, int& A, int& B)//средний уровень сложности  
{
    do
    {
        B++;
        if ((B > 10) || (ARR[A][B] == 9) || (ARR[A][B] == 0))
        {
            B -= 2;
            if ((ARR[A][B] == 9) || (ARR[A][B] == 0))
            {
                B++;
                A--;
                if ((A < 1) || (ARR[A][B] == 9) || (ARR[A][B] == 0))
                {
                    A += 2;
                }
            }
        }

        if ((ARR[A][B] == 9) || (ARR[A][B] == 0) || (A > 10))
        {
            A = rand() % 10 + 1;
            B = rand() % 10 + 1;
            cout << "Сработал рандом" << endl;
        }

        if ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4))
        {
            cout << A << " " << B << endl;
            cout << "Есть попадание из ShootingCompComplexity_1" << endl;
            ARR[A][B] = 9;
        }
    } while ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4) || (ARR[A][B] == 9) || (ARR[A][B] == 0));
    if (ARR[A][B] == 10)
    {
        cout << A << " " << B << endl;
        cout << "Мимо из ShootingCompComplexity_1" << endl;
        ARR[A][B] = 0;
        J = 0;
    }
}
void ShootingCompComplexity_2(int** ARR, int rows, int cols, int& A, int& B)// высокий уровень сложности 
{

    do {
        B -= 2;
        if ((B < 1) || (ARR[A][B] == 0) || (ARR[A][B] == 9))
        {
            B++;
            A++;
        }
        if ((A > 10) || (ARR[A][B] == 0) || (ARR[A][B] == 9))
        {
            A -= 2;
        }
        if ((ARR[A][B] == 0) || (ARR[A][B] == 9) || (A < 1))
        {
            A = rand() % 10 + 1;
            B = rand() % 10 + 1;
        }
        if ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4))
        {
            cout << A << " " << B << endl;
            cout << "Есть попадание из ShootingCompComplexity_2" << endl;
            ARR[A][B] = 9;
            B++;
        }
    } while ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4) || (ARR[A][B] == 0) || (ARR[A][B] == 9));
    if (ARR[A][B] == 10)
    {
        cout << A << " " << B << endl;
        cout << "Мимо из ShootingCompComplexity_2" << endl;
        ARR[A][B] = 0;
        J = 0;
    }
}
void ShootingCompComplexity_3(int** ARR, int rows, int cols, int& A, int& B)
{
    do {
        A++;
        B++;
        if (A > 10)
        {
            A -= 2;
        }
        if ((ARR[A][B] == 0) || (ARR[A][B] == 9))
        {
            A = rand() % 10 + 1;
            B = rand() % 10 + 1;
        }
        if ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4))
        {
            cout << A << " " << B << endl;
            cout << "Есть попадание из ShootingCompComplexity_3" << endl;
            ARR[A][B] = 9;
            B--;
        }
    } while ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4) || (ARR[A][B] == 0) || (ARR[A][B] == 9));
    if (ARR[A][B] == 10)
    {
        cout << A << " " << B << endl;
        cout << "Мимо из ShootingCompComplexity_3" << endl;
        ARR[A][B] = 0;
        J = 0;
    }
}
void ShootingCompComplexity_4(int** ARR, int rows, int cols, int& A, int& B)
{
    do
    {
        A--;
        if ((A < 1) || (ARR[A][B] == 0) || (ARR[A][B] == 9))
        {
            A = rand() % 10 + 1;
            B = rand() % 10 + 1;
        }

        if ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4))
        {
            cout << "Есть попадание из ShootingCompComplexity_4" << endl;
            cout << A << " " << B << endl;
            ARR[A][B] = 9;
        }
    } while ((ARR[A][B] == 1) || (ARR[A][B] == 2) || (ARR[A][B] == 3) || (ARR[A][B] == 4) || (ARR[A][B] == 0) || (ARR[A][B] == 9));
    if (ARR[A][B] == 0)
    {
        cout << "Мимо из ShootingCompComplexity_4" << endl;
        cout << A << " " << B << endl;
        ARR[A][B] = 0;
        J = 0;
    }
}


void ShootingPlayer(char** ARR, int rows, int cols)
{
    setlocale(LC_ALL, "ru");
    int R;
    int C;
    cout << "Введите координаты для стрельбы:" << endl;
    cin >> R;
    cout << "   ";
    cin >> C;
    cout << endl;
    if (ARR[R][C] == 'X')
    {
        cout << "В эту точку вы уже стреляли, введите новые координаты:" << endl;
        cin >> R;
        cout << "   ";
        cin >> C;
        cout << endl;
    }
    if (ARR[R][C] == '0')
    {
        cout << "мимо" << endl;
        ARR[R][C] = 'X';
    }
    else {
        cout << "Есть попадание!" << endl;
        ARR[R][C] = 'X';
        ShootingPlayer(ARR, rows, cols);
    }
}
void locationsPlayer(int** ARR, int rows, int cols)
{
    srand(time(NULL));
    int R;
    int C;

    do {                          // расстановка четырехпалубного корабля
        R = rand() % 7 + 1;
        C = rand() % 10 + 1;
    } while (0);

    ARR[R][C] = 4;
    ARR[R + 1][C] = 4;
    ARR[R + 2][C] = 4;
    ARR[R + 3][C] = 4;

    do {
        R = rand() % 10 + 1;// расстановка трёхпалубных кораблей
        C = rand() % 8 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R][C + 2] != 0)
        || (ARR[R][C + 3] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 2] != 0) || (ARR[R - 1][C + 2] != 0) || (ARR[R + 1][C + 1] != 0) ||
        (ARR[R - 1][C + 1] != 0));

    ARR[R][C] = 3;
    ARR[R][C + 1] = 3;
    ARR[R][C + 2] = 3;


    do {
        R = rand() % 8 + 1;
        C = rand() % 10 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R + 2][C] != 0) || (ARR[R + 3][C] == 4) || (ARR[R + 3][C] == 3) ||
        (ARR[R][C] != 0) || (ARR[R - 1][C] == 4) || (ARR[R - 1][C] == 3) || (ARR[R][C - 1] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R + 2][C + 1] != 0) ||
        (ARR[R + 1][C - 1] != 0) || (ARR[R + 2][C - 1] != 0));

    ARR[R][C] = 3;
    ARR[R + 1][C] = 3;
    ARR[R + 2][C] = 3;

    for (int i{ 0 }; i < 2; i++)// расстановка двухпалубных кораблей
    {
        do {
            R = rand() % 10 + 1;
            C = rand() % 9 + 1;
        } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0)
            || (ARR[R][C + 2] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R - 1][C + 1] != 0) ||
            (ARR[R + 1][C + 2] != 0) || (ARR[R - 1][C + 2] != 0));

        ARR[R][C] = 2;
        ARR[R][C + 1] = 2;

    }
    do {
        R = rand() % 9 + 1;
        C = rand() % 10 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R + 1][C - 1] != 0) ||
        (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R + 2][C] != 0));

    ARR[R][C] = 2;
    ARR[R + 1][C] = 2;


    for (int i{ 0 }; i < 4; i++)// расстановка однопалубных кораблей
    {
        do {
            R = rand() % 10 + 1;
            C = rand() % 10 + 1;
        } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R][C + 1] != 0));
        {
            ARR[R][C] = 1;
        }
    }

    for (int i{ 0 }; i < rows; i++)
        for (int j{ 0 }; j < cols; j++)
        {
            if (ARR[i][j] == 0)
                ARR[i][j] = 10;
        }
}
void locationsComp(int** ARR, int rows, int cols)
{
    srand(time(NULL) + 100);
    int R;
    int C;
    do {                          // расстановка четырехпалубного корабля
        R = rand() % 7 + 1;
        C = rand() % 10 + 1;
    } while (0);

    ARR[R][C] = 4;
    ARR[R + 1][C] = 4;
    ARR[R + 2][C] = 4;
    ARR[R + 3][C] = 4;

    do {
        R = rand() % 10 + 1;// расстановка трёхпалубных кораблей
        C = rand() % 8 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R][C + 2] != 0)
        || (ARR[R][C + 3] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 2] != 0) || (ARR[R - 1][C + 2] != 0) || (ARR[R + 1][C + 1] != 0) ||
        (ARR[R - 1][C + 1] != 0));

    ARR[R][C] = 3;
    ARR[R][C + 1] = 3;
    ARR[R][C + 2] = 3;


    do {
        R = rand() % 8 + 1;
        C = rand() % 10 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R + 2][C] != 0) || (ARR[R + 3][C] == 4) || (ARR[R + 3][C] == 3) ||
        (ARR[R][C] != 0) || (ARR[R - 1][C] == 4) || (ARR[R - 1][C] == 3) || (ARR[R][C - 1] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R + 2][C + 1] != 0) ||
        (ARR[R + 1][C - 1] != 0) || (ARR[R + 2][C - 1] != 0));

    ARR[R][C] = 3;
    ARR[R + 1][C] = 3;
    ARR[R + 2][C] = 3;

    for (int i{ 0 }; i < 2; i++)// расстановка двухпалубных кораблей
    {
        do {
            R = rand() % 10 + 1;
            C = rand() % 9 + 1;
        } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0)
            || (ARR[R][C + 2] != 0) || (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R - 1][C + 1] != 0) ||
            (ARR[R + 1][C + 2] != 0) || (ARR[R - 1][C + 2] != 0));

        ARR[R][C] = 2;
        ARR[R][C + 1] = 2;

    }
    do {
        R = rand() % 9 + 1;
        C = rand() % 10 + 1;
    } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R + 1][C - 1] != 0) ||
        (ARR[R][C + 1] != 0) || (ARR[R + 1][C + 1] != 0) || (ARR[R + 2][C] != 0));

    ARR[R][C] = 2;
    ARR[R + 1][C] = 2;


    for (int i{ 0 }; i < 4; i++)// расстановка однопалубных кораблей
    {
        do {
            R = rand() % 10 + 1;
            C = rand() % 10 + 1;
        } while ((ARR[R + 1][C] != 0) || (ARR[R][C] != 0) || (ARR[R - 1][C] != 0) || (ARR[R][C - 1] != 0) || (ARR[R][C + 1] != 0));
        {
            ARR[R][C] = 1;
        }

    }
    for (int i{ 0 }; i < rows; i++)
        for (int j{ 0 }; j < cols; j++)
        {
            if (ARR[i][j] == 0)
                ARR[i][j] = 10;
        }
}

bool Chek(int** ARR, int cows, int rows)
{
    int y = 0;
    for (int i{ 0 }; i < cows; i++)
    {
        for (int j{ 0 }; j < rows; j++)
        {
            if (ARR[i][j] == 9)
            {
                y++;
            }
        }
    }
    if (y == 20)return 0;
    else return 1;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int P = 0;
    int P1 = 3;
    int w = 32;
    int H = 0;
    int m = 0;//итератор для вызова функции с разными уровнями сложности
    int Rows = 12;
    int Cols = 12;
    int** Field_1 = new int* [Rows];
    for (int i = 0; i < Rows; i++)
    {
        Field_1[i] = new int[Cols] {0};
    }
    int** Field_2 = new int* [Rows];
    for (int i = 0; i < Rows; i++)
    {
        Field_2[i] = new int[Cols] {0};
    }
    int** arrLogik = new int* [Rows];
    for (int i = 0; i < Rows; i++)
    {
        arrLogik[i] = new int[Cols] {0};
    }
    locationsPlayer(Field_1, Rows, Cols);
    locationsComp(arrLogik, Rows, Cols);
    for (int i{ 0 }; i < Rows; i++)
    {
        for (int j{ 0 }; j < Cols; j++)
        {
            Field_2[i][j] = 10;
        }
    }

    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Hello World - SFML");
    sf::Font myFont;
    myFont.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    sf::Text myText("0", myFont, 40);
    sf::Text myTextFinish_1("0", myFont, 40);
    sf::Text myTextFinish_2("0", myFont, 40);
    sf::Texture t;
    t.loadFromFile("tiles.jpg");
    sf::Sprite s(t);
    myText.setPosition(50, 50);
    myText.setFillColor(sf::Color::Green);
    myText.setString(L"Выберите сложность игры:\n\n\t1 - Легкая\n\t2 - Средняя\n\t3 - Сложная");
    myTextFinish_1.setPosition(50, 50);
    myTextFinish_1.setFillColor(sf::Color::Green);
    myTextFinish_1.setString(L"Игра окончена\n\n\tВы проиграли\n\n");
    myTextFinish_1.setPosition(50, 50);
    myTextFinish_1.setFillColor(sf::Color::Green);
    myTextFinish_2.setString(L"Игра окончена\n\n\tВы выйграли\n\n\tУРА!!!\n\n\tПоздравляем");
    while (app.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(app);
        int x = (pos.x - 400) / w;
        int y = pos.y / w;
        sf::Event event;
        app.clear(sf::Color(0, 0, 255));
        if (P == 0)
        {
            app.draw(myText);
        }


        while (app.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                app.close();
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1))
            {
                P = 1;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2))
            {
                P = 2;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3))
            {
                P = 3;
            }


            if ((event.type == sf::Event::MouseButtonPressed))
                if (event.key.code == sf::Mouse::Left)
                {

                    Field_2[x][y] = arrLogik[x][y];
                    if (arrLogik[x][y] == 10)
                    {
                        Field_2[x][y] = 0;
                        if (P > 3) P -= P1;
                    }
                    if (arrLogik[x][y] != 10)
                    {
                        Field_2[x][y] = 9;
                        P += P1;
                    }
                    if (P == 1)
                    {

                        ShootingComp(Field_1, Rows, Cols);
                        while (J)
                        {
                            ShootingComp(Field_1, Rows, Cols);
                        }
                    }

                    if (P == 2)
                    {
                        if (J == 0)
                            ShootingComp(Field_1, Rows, Cols);
                        else if (J == 1)
                        {
                            ShootingCompComplexity_1(Field_1, Rows, Cols, r, c);

                        }

                    }
                    if (P == 3)
                    {
                        if ((m == 0) && (!J))
                        {
                            ShootingComp(Field_1, Rows, Cols);
                            if (J)
                            {
                                ShootingCompComplexity_1(Field_1, Rows, Cols, r, c);
                                m++;
                            }
                        }

                        else if ((m == 1) && (!J))
                        {
                            ShootingCompComplexity_2(Field_1, Rows, Cols, r, c);
                            m++;
                        }
                        else if ((m == 2) && (!J))
                        {
                            ShootingCompComplexity_3(Field_1, Rows, Cols, r, c);
                            m++;
                        }
                        else if ((m == 3) && (!J))
                        {
                            ShootingCompComplexity_3(Field_1, Rows, Cols, r, c);
                            m++;
                        }
                        else if ((m == 4) && (!J))
                        {
                            ShootingCompComplexity_4(Field_1, Rows, Cols, r, c);
                            m = 0;
                        }
                    }

                }

        }


        Chek(Field_1, Rows, Cols);
        if (P == 1) {

            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_1[j][i] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);
                }
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_2[i][j] * w, 0, w, w));
                    s.setPosition(i * w + 400, j * w);
                    app.draw(s);
                }
            }

        }
        if (P == 2)
        {
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_1[j][i] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);
                }
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_2[i][j] * w, 0, w, w));
                    s.setPosition(i * w + 400, j * w);
                    app.draw(s);
                }
            }
        }
        if (P == 3)
        {
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_1[j][i] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);
                }
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_2[i][j] * w, 0, w, w));
                    s.setPosition(i * w + 400, j * w);
                    app.draw(s);
                }
            }
        }
        if (P > 3)
        {
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_1[j][i] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);
                }
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(sf::IntRect(Field_2[i][j] * w, 0, w, w));
                    s.setPosition(i * w + 400, j * w);
                    app.draw(s);
                }
            }
        }
        if (!Chek(Field_1, Rows, Cols))
        {
            app.clear(sf::Color(0, 0, 255));
            app.draw(myTextFinish_1);

        }

        if (!Chek(Field_2, Rows, Cols))
        {
            app.clear(sf::Color(0, 0, 255));
            app.draw(myTextFinish_2);

        }

        app.display();
    }



}