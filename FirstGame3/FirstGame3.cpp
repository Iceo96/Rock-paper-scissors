#include<cstdlib>
#include <iostream>
using namespace std;
enum enOpType{Add = 1, Sub =2, Mul = 3, Div = 4, MixOpType = 5};
enum enHardLevel{Easy = 1, Normal = 2, Hard = 3, Mix = 4};
struct stRoundRequmient {
    enHardLevel HardLevel;
    short Num1;
    short Num2;
    enOpType OpType;
    short Result;
    short UserEnterd;

};
struct stFinalResult {
    short NumberOfQuestion = 0;
    enHardLevel HardLevel;
    string NameHardLevel;
    enOpType OpType;
    string NameOpType;
    short NumberRightAnswer=0;
    short NumberWrongAnswer=0;
};
int RandomNumber(int From, int To) {
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}
short RoundsHardLevel(enHardLevel HardLevel) {
    switch (HardLevel)
    {
    case Easy:
        return RandomNumber(0, 10);  
        break;
    case Normal:
        return RandomNumber(10, 20);
        break;
    case Hard:
        return RandomNumber(20, 99);
        break;
    case Mix:
        return RandomNumber(0, 99);
        break;
    default:
        break;
    }
}
enHardLevel ChooseHardLevel() {
    short HardLevel = 0;
    do
    {
        cout << "Enter a questions level,  Easy[1] Normal[2] Hard[3] Mix[4]?";
        cin >> HardLevel;
    } while (HardLevel < 0 ||  HardLevel > 4);
    return (enHardLevel)HardLevel;
}
enOpType ChooseOpType() {
    short OpType;
    cout << "Please enter A Operation type, Add[1] Sub[2] Mul[3] Div[4] Mix[5]?";
    cin >> OpType;
    return (enOpType)OpType;
}
char CharOPType(enOpType OpType) {
    char ArrChar[] = { '+','-','*','/' };
    if (OpType == enOpType::MixOpType)
        return ArrChar[RandomNumber(1, 4) - 1];
    else
        return ArrChar[OpType - 1];
}
string NameChar(enOpType optype) {
    string ArrOpType[] = { "Add","Sub","Mul","Div","MixOpType"};
    return ArrOpType[optype - 1];
}
string NameHardLevel(enHardLevel HardLevel) {
    string ArrHardName[] = {"Easy","Normal","Hard","Mix"};
    return ArrHardName[HardLevel - 1];
}
short CalculateFinalResult(stRoundRequmient RoundRequmient, char ChooseChar) {
    switch (ChooseChar)
    {
    case '+':
        return RoundRequmient.Num1 + RoundRequmient.Num2;
        break;
    case '-':
        return RoundRequmient.Num1 - RoundRequmient.Num2;
        break;
    case '*':
        return RoundRequmient.Num1 * RoundRequmient.Num2;
        break;
    case '/':
        return RoundRequmient.Num1 / RoundRequmient.Num2;
        break;
    default:
        break;
    }
}
void PrintRoundResult(stRoundRequmient RoundRequiment, char CharType, short questionNum, short& CounsPass, short& CountFill) {
    cout << "\n[Question " << questionNum << "]\n\n";
    cout << RoundRequiment.Num1 << endl;
    cout << "   " << CharType << endl;
    cout << RoundRequiment.Num2 << endl;
    cout << "------\n";
    cin >> RoundRequiment.UserEnterd;
    if (RoundRequiment.UserEnterd == RoundRequiment.Result)
    {
        cout << "Right Answer: : - )\n";
        CounsPass++;
        system("color 2F");

    }
    else if (RoundRequiment.Result != RoundRequiment.Result)
    {
        cout << "Wrong Answer : - (\n";
        CountFill++;
        system("color 4F");
        cout << "\a";
    }
}
string FinalGameResult(stFinalResult finalResult){
    if (finalResult.NumberRightAnswer > finalResult.NumberWrongAnswer)
    {
        system("color 2F");
        return "Final result is pass : - )";
    }
    else if (finalResult.NumberWrongAnswer > finalResult.NumberRightAnswer)
    {
        system("color 4F");
        return "Final result isn't pass : - (";
        cout << '\a';

    }

}
stFinalResult FillFinalResult(stRoundRequmient roundRequmient, short NumOfQuestion, short RightAnswer, short WrongAnswer) {
    stFinalResult FillFinalResult;
    FillFinalResult.NumberOfQuestion = NumOfQuestion;
    FillFinalResult.NameHardLevel = NameHardLevel(roundRequmient.HardLevel);
    FillFinalResult.OpType = roundRequmient.OpType;
    FillFinalResult.NameOpType = NameChar(roundRequmient.OpType);
    FillFinalResult.NumberRightAnswer = RightAnswer;
    FillFinalResult.NumberWrongAnswer = WrongAnswer;
    return FillFinalResult;
}
void FinalResult(stFinalResult FinalResult) {
    cout << "Number of questions : " << FinalResult.NumberOfQuestion << endl;
    cout << "Question level : " << FinalResult.NameHardLevel << endl;
    cout << "OpType : " << FinalResult.NameOpType << endl;
    cout << "Num of Won Time : " << FinalResult.NumberRightAnswer << endl;
    cout << "Num of Loss Time : " << FinalResult.NumberWrongAnswer << endl;

}
stFinalResult PlayGame(short NumOfQuestion) {
    stRoundRequmient RoundRequiment;
    short countpass = 0, countfil = 0;
    short ChooseChar;
    short UserEnterdResult;
    enHardLevel roundHardLevel = ChooseHardLevel();
    enOpType ChooseType = ChooseOpType();


    for (short QuestionN= 0; QuestionN <= NumOfQuestion; QuestionN++)
    {
        RoundRequiment.HardLevel = roundHardLevel;
        RoundRequiment.Num1 = RoundsHardLevel(roundHardLevel);
        RoundRequiment.Num2 = RoundsHardLevel(roundHardLevel);
        RoundRequiment.OpType = ChooseType;
        ChooseChar = CharOPType(ChooseType);
        RoundRequiment.Result = CalculateFinalResult(RoundRequiment, ChooseChar);
        PrintRoundResult(RoundRequiment, ChooseChar, QuestionN, countpass, countfil);
    }
    return FillFinalResult(RoundRequiment, NumOfQuestion, countpass, countfil);

}
void ShowGameView(stFinalResult finalResult) {
    cout << "\n--------------\n\n";
    cout << FinalGameResult(finalResult) << endl;
    cout << "\n---------------\n";
}
void RestScreen() {
    system("cls");
    system("color 0F");

}
short NumOfQuestion() {
    short NumoFQuestion = 0;
    cout << "Enter a Num of Questions ? ";
    cin >> NumoFQuestion;
    return NumoFQuestion;
}
void StartGame() {

    char Choose = 'y';
    stFinalResult finaResult;
    do
    {
        RestScreen();
        finaResult = PlayGame(NumOfQuestion());
        ShowGameView(finaResult);
        FinalResult(finaResult);
        cout << "Do you want to play again ?? y/n";
        cin >> Choose;
    } while (Choose == 'Y' || Choose == 'y');
}
int main()
{
    StartGame();
}


