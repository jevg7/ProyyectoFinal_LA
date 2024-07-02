#define MAX 100
#define MAXID 14

 struct ESTUDENTS{
    std::string NAME;
    int CIF;
    int AGE;
    std::string CAREER ;
}persona;

 struct REGISTRERS{
   std::string ID  ;
   std:: string NAME  ; 
}persona2;

struct MATCHES{
    int ID;
    std::string DATE;
    std::string HOUR;
    std::string LOCAL;
    std::string VISIT;
    int LOCALPOINTS;
    int VISITPOINTS;
}partido[MAX];

struct ASSIST{
    int ID;
}Ids[MAX];



