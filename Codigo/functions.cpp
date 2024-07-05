#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include "variables.h"
#include <regex>

using namespace std;

int contador = 0;
int id = 0;

/*Funciones prototipo*/
void student();
void registrer();
int menu();
void principal();
void studentdata();
void registrerdata();
void showregistrerdata();
void studentOptions();
void registrerOptions();
void showstudentdata();
void showmatchdata();
void addmatch();
void assisted();
void saveMatches();
void loadMatches();


/*Validaciones*/

bool isStudentDataEntered = false;
bool isRegistrerDataEntered = false;


bool isValidRegistrerMenuOption(const std::string &optionStr)
{
    std::regex menuRegex("^[1-3]$");
    return std::regex_match(optionStr, menuRegex);
}

bool isValidStudentMenuOption(const std::string &optionStr)
{
    std::regex menuRegex("^[1-4]$");
    return std::regex_match(optionStr, menuRegex);
}

bool isValidMenuOption(const std::string &optionStr)
{
    std::regex menuRegex("^[1-3]$");
    return std::regex_match(optionStr, menuRegex);
}

bool isValidDateFormat(const std::string &dateStr)

{
    std::regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/\\d{4}$");
    return std::regex_match(dateStr, dateRegex);
}

bool isValidTimeFormat(const std::string &timeStr)
{
    std::regex timeRegex("^(0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");
    return std::regex_match(timeStr, timeRegex);
}

bool isValidStudentName(const std::string &nameStr)
{
    std::regex nameRegex("^[a-zA-Z]+\\s[a-zA-Z]+$");
    return std::regex_match(nameStr, nameRegex);
}

bool isValidCIF(const std::string &cifStr)
{
    std::regex cifRegex("^\\d{8}$");
    return std::regex_match(cifStr, cifRegex);
}

bool isValidAge(const std::string &ageStr)
{
    std::regex ageRegex("^(1[5-9]|[2-9][0-9])$");
    return std::regex_match(ageStr, ageRegex);
}

bool isValidCareer(const std::string &careerStr)
{
    std::regex careerRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(careerStr, careerRegex);
}

bool isValidID(const std::string &idStr)
{
    std::regex idRegex("^[0-9]{3}-[0-9]{6}-[0-9]{4}[a-zA-Z]$");
    return std::regex_match(idStr, idRegex);
}

bool isValidRegistrerName(const std::string &nameStr)
{
    std::regex nameRegex("^[a-zA-Z]+\\s[a-zA-Z]+$");
    return std::regex_match(nameStr, nameRegex);
}

bool isLocalTeamValid(const std::string &localTeamStr)
{
    std::regex localTeamRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(localTeamStr, localTeamRegex);
}

bool isVisitTeamValid(const std::string &visitTeamStr)
{
    std::regex visitTeamRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(visitTeamStr, visitTeamRegex);
}

bool isMatchIDValid(const std::string &MatchIdStr)
{
    std::regex MatchIdRegex("^\\d{1,3}$");
    return std::regex_match(MatchIdStr, MatchIdRegex);
}

bool isLocalPointsValid(const std::string &localPointsStr)
{
    if (localPointsStr.empty())
    {
        return false;
    }

    for (char c : localPointsStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

bool isVisitPointsValid(const std::string &visitPointsStr)
{
    if (visitPointsStr.empty())
    {
        return false;
    }

    for (char c : visitPointsStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

void saveCounter()
{
    ofstream file("counter.txt");
    if (file.is_open())
    {
        file << contador;
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar el contador." << endl;
    }
}

void loadCounter()
{
    ifstream file("counter.txt");
    if (file.is_open())
    {
        file >> contador;
        file.close();
    }
    else
    {

        contador = 0;
    }
}

/*Funciones*/
int menu()
{
    int opt;

    while (true)
    {
        string optStr;
        cout << "Bienvenido al sistema de control de partidos de Baloncesto" << endl;
        cout << "!Vamos Jaguares!" << endl;
        cout << "1. Modo estudiante" << endl;
        cout << "2. Modo registrador" << endl;
        cout << "3. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> optStr;
        system("cls");
        if (isValidMenuOption(optStr))
        {
            opt = stoi(optStr);
            break;
        }
        else
        {
            cout << "Ingrese una opcion valida\n";
            system("pause");
            system("cls");
        }
    }
    return opt;
}

void principal()
{
    // loadCounter();
    loadMatches();
    int opt;
    do
    {
        opt = menu();
        system("cls");
        switch (opt)
        {
        case 1:
            student();
            system("cls");
            break;
        case 2:
            registrer();
            system("cls");
            break;
        case 3:
            cout << "Hasta pronto" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return principal();
        }
    } while (opt != 3);
}

void studentdata()
{
    std::string tester = "";
    std::string tester2 = "";

    if (isStudentDataEntered)
    {
        cout << "La informacion ya ha sido ingresada." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (true)
    {
        cout << "Ingrese su nombre y apellido" << endl;
        cin.ignore();
        getline(cin, persona.NAME);
        system("cls");

        if (isValidStudentName(persona.NAME))
        {
            break;
        }
        else
        {
            cout << "Ingrese un nombre valido\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su CIF" << endl;
        cin >> tester;
        system("cls");

        if (isValidCIF(tester))
        {
            persona.CIF = stoi(tester);
            break;
        }
        else
        {
            cout << "Ingrese un CIF valido de 8 digitos\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su edad" << endl;
        cin >> tester2;
        system("cls");

        if (isValidAge(tester2))
        {
            persona.AGE = stoi(tester2);
            break;
        }
        else
        {
            cout << "Ingrese una edad valida entre 15 y 99\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su carrera" << endl;
        cin.ignore();
        getline(cin, persona.CAREER);
        system("cls");

        if (isValidCareer(persona.CAREER))
        {
            break;
        }
        else
        {
            cout << "Ingrese una carrera valida\n";
            system("pause");
            system("cls");
        }
    }

    isStudentDataEntered = true;
}

void registrerdata()
{
    if (isRegistrerDataEntered)
    {
        cout << "La informacion ya ha sido ingresada." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (true)
    {
        cout << "Ingrese su cedula (Con guiones)" << endl;
        cin >> persona2.ID;
        system("cls");

        if (isValidID(persona2.ID))
        {
            break;
        }
        else
        {
            cout << "Ingrese en el formato indicado\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su nombre y Apellido" << endl;
        cin.ignore();
        getline(cin, persona2.NAME);
        system("cls");

        if (isValidRegistrerName(persona2.NAME))
        {
            break;
        }
        else
        {
            cout << "Ingrese un nombre valido\n";
            system("pause");
            system("cls");
        }
    }

    isRegistrerDataEntered = true;
}

void studentOptions()
{
    int opt;
    while (true)
    {
        string optStr;
        cout << "1. Ver datos" << endl;
        cout << "2. Ver partidos" << endl;
        cout << "3. Asistir a un partido" << endl;
        cout << "4. Volver" << endl;
        cout << "Ingrese una opcion: ";
        cin >> optStr;
        system("cls");
        if (isValidStudentMenuOption(optStr))
        {
            opt = stoi(optStr);
            break;
        }
        else
        {
            cout << "Ingrese una opcion valida\n";
            system("pause");
            system("cls");
        }
    }
    do
    {
        switch (opt)
        {
        case 1:
            showstudentdata();
            system("pause");
            system("cls");
            break;
        case 2:
            showmatchdata();
            system("pause");
            system("cls");
            break;
        case 3:
            assisted();
            system("pause");
            system("cls");
            break;
        case 4:
            return;
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return studentOptions();
        }
        while (true)
        {
            string optStr;
            cout << "1. Ver datos" << endl;
            cout << "2. Ver partidos" << endl;
            cout << "3. Asistir a un partido" << endl;
            cout << "4. Volver" << endl;
            cout << "Ingrese una opcion: ";
            cin >> optStr;
            system("cls");
            if (isValidStudentMenuOption(optStr))
            {
                opt = stoi(optStr);
                break;
            }
            else
            {
                cout << "Ingrese una opcion valida\n";
                system("pause");
                system("cls");
            }
        }
    } while (opt != 4);
}

void showstudentdata()
{
    cout << "Nombre: " << persona.NAME << endl;
    cout << "CIF: " << persona.CIF << endl;
    cout << "Edad: " << persona.AGE << endl;
    cout << "Carrera: " << persona.CAREER << endl;
}

void addmatch()
{
    char choice;

    do
    {
        cout << "Ingrese la información del partido #" << (contador + 1) << ":" << endl;
        while (true)
        {
            cout << "Fecha (DD/MM/YYYY): ";
            cin >> partido[contador].DATE;
            if (isValidDateFormat(partido[contador].DATE))
            {
                break;
            }
            else
            {
                cout << "Ingrese un formato de fecha valido DD/MM/YYYY \n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Hora (HH:MM): ";
            cin >> partido[contador].HOUR;
            if (isValidTimeFormat(partido[contador].HOUR))
            {
                break;
            }
            else
            {
                cout << "Ingrese un formato de hora valido HH:MM \n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Equipo Local: ";
            cin.ignore();
            getline(cin, partido[contador].LOCAL);
            if (isLocalTeamValid(partido[contador].LOCAL))
            {
                break;
            }
            else
            {
                cout << "Ingrese un nombre de equipo local valido\n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Equipo Visitante: ";
            getline(cin, partido[contador].VISIT);
            if (isVisitTeamValid(partido[contador].VISIT))
            {
                break;
            }
            else
            {
                cout << "Ingrese un nombre de equipo visitante valido\n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Puntos del equipo local: ";
            cin >> partido[contador].LOCALPOINTS;
            if (isLocalPointsValid(to_string(partido[contador].LOCALPOINTS)))
            {
                break;
            }
            else
            {
                cout << "Ingrese un numero de puntos valido\n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Puntos del equipo visitante: ";
            cin >> partido[contador].VISITPOINTS;
            if (isVisitPointsValid(to_string(partido[contador].VISITPOINTS)))
            {
                break;
            }
            else
            {
                cout << "Ingrese un numero de puntos valido\n";
                system("pause");
                system("cls");
            }
        }

        partido[contador].ID = contador + 1;

        contador++;
        saveMatches();
        saveCounter();

        cout << "¿Desea ingresar otro partido? (s/n): ";
        cin >> choice;

    } while (choice == 's' || choice == 'S');
}

void showmatchdata()
{
    loadMatches();
    for (int i = 0; i < contador; i++)
    {

        cout << "ID: " << partido[i].ID << endl;
        cout << "Fecha: " << partido[i].DATE << endl;
        cout << "Hora: " << partido[i].HOUR << endl;
        cout << "Equipo Local: " << partido[i].LOCAL << endl;
        cout << "Equipo Visitante: " << partido[i].VISIT << endl;
        cout << "Puntos del equipo local: " << partido[i].LOCALPOINTS << endl;
        cout << "Puntos del equipo visitante: " << partido[i].VISITPOINTS << endl;
        cout << "-----------------------------------" << endl;
    }
    contador = 0;
}

void assisted()
{
    string tester = "";
    showmatchdata();

    char choice;
    do
    {
        while (true)
        {
            cout << "Ingrese la id del partido al que asistio:" << endl;
            cin >> tester;
            system("cls");

            if (isMatchIDValid(tester))
            {
                id = stoi(tester);
                break;
            }
            else
            {
                cout << "Ingrese un ID valido\n";
                system("pause");
            }
        }
        cout  << "Usted asistio al partido" << endl;
        cout << "¿Desea ingresar otra asistencia? (s/n): ";
        cin >> choice;
        system("cls");

    } while (choice == 's' || choice == 'S');
}


void registrerOptions()
{
    int opt;
    do
    {
        string optStr;
        cout << "1. Ver datos" << endl;
        cout << "2. Ingresar partido" << endl;
        cout << "3. Volver" << endl;
        cout << "Ingrese una opcion: ";
        cin >> optStr;
        system("cls");
        if (isValidRegistrerMenuOption(optStr))
        {
            opt = stoi(optStr);
            break;
        }
        else
        {
            cout << "Ingrese una opcion valida\n";
            system("pause");
            system("cls");
        }
    } while (true);

    do
    {
        switch (opt)
        {
        case 1:
            showregistrerdata();
            system("pause");
            system("cls");
            break;
        case 2:
            addmatch();
            system("pause");
            system("cls");
            break;
        case 3:
            return principal();
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return registrerOptions();
        }
    } while (opt != 3);
}

void showregistrerdata()
{
    cout << "Cedula: " << persona2.ID << endl;
    cout << "Nombre: " << persona2.NAME << endl;
}

void student()
{
    studentdata();
    studentOptions();
}

void registrer()
{
    registrerdata();
    registrerOptions();
}

void saveMatches()
{
    ofstream file("matches.txt", ios::app);
    if (file.is_open())
    {
        int start = contador - 1;
        for (int i = start; i < contador; ++i)
        {
            file << partido[i].ID << "," << partido[i].DATE << "," << partido[i].HOUR << ","
                 << partido[i].LOCAL << "," << partido[i].VISIT << ","
                 << partido[i].LOCALPOINTS << "," << partido[i].VISITPOINTS << endl;
        }
        file.close();
        cout << "Partidos guardados exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar los partidos." << endl;
    }
}

void loadMatches()
{
    ifstream file("matches.txt");
    if (file.is_open())
    {
        contador = 0;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            int i = 0;
            while (getline(ss, token, ','))
            {
                switch (i)
                {
                case 0:
                    partido[contador].ID = stoi(token);
                    break;
                case 1:
                    partido[contador].DATE = token;
                    break;
                case 2:
                    partido[contador].HOUR = token;
                    break;
                case 3:
                    partido[contador].LOCAL = token;
                    break;
                case 4:
                    partido[contador].VISIT = token;
                    break;
                case 5:
                    partido[contador].LOCALPOINTS = stoi(token);
                    break;
                case 6:
                    partido[contador].VISITPOINTS = stoi(token);
                    break;
                }
                i++;
            }
            contador++;
        }
        file.close();
    }
}
