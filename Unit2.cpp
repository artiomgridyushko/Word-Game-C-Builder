#include <vcl.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
vector<string> availableWords;
vector<string> usedWords; // ������ ��� �������� �������������� ����
vector<string> words1; // ������ ���� ��� ������� ������ ���������
vector<string> words2; // ������ ���� ��� ������� ������ ���������
vector<string> words3; // ������ ���� ��� �������� ������ ���������
int randIndex = -1;
string word = "";
int guessedWords = 0;
int gameSeconds[5] = {0}; // ������ ��� �������� ������� �� ������ ���������� � ������� ����
int attemptsLeft = 3; // ���������� ������� �� ���������� �����
AnsiString wordValue;
AnsiString PlayerName;
int totalTime=0;
int kol;
int guessedWordsCount;
int level;

vector<string> loadWordsFromFile(string filename) {
    vector<string> words;
    ifstream file(filename);
	if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    }
	return words;
}

void shuffle(string& str) {
	for (int i = 0; i < str.length() - 1; i++) {
        int j = rand() % (str.length() - i) + i;
        swap(str[i], str[j]);
    }
}

void addLetters(string& str) {
	string extraLetters = "������������������������������";
    for (int i = 0; i < 2; i++) {
        int index = rand() % (str.length() + 1);
        char c = extraLetters[rand() % extraLetters.length()];
		while (c > 127) {
            c = extraLetters[rand() % extraLetters.length()];
        }
        str.insert(index, 1, c);
    }
}

void startGame() {
	srand(time(NULL)); // ������������� ��������� �������� ��� ���������� ��������� �����

 vector<string> availableWords;

	if (Form1->RadioButton1->Checked) // ���� ������ ������ �������
	{
		availableWords = loadWordsFromFile("words1.txt");
		level = 1;
	}

	if (Form1->RadioButton2->Checked) // ���� ������ ������ �������
	{
		availableWords = loadWordsFromFile("words2.txt");
		level = 2;
	}

	if (Form1->RadioButton3->Checked) // ���� ������ ������ �������
	{
        availableWords = loadWordsFromFile("words3.txt");
        level = 3;
    }

    // ������� �������������� ����� �� ���������
    for (int i = 0; i < usedWords.size(); i++) {
        availableWords.erase(remove(availableWords.begin(), availableWords.end(), usedWords[i]), availableWords.end());
	}

	randIndex = rand() % availableWords.size();
    word = availableWords[randIndex]; // �������� ����� �� ���������� �������
    usedWords.push_back(word); // ��������� ����� � ������ ��������������

    if (availableWords.size() == 0) {
		usedWords.clear(); // ������� ������ �������������� ����
    }

    string shuffled = word;
	shuffle(shuffled);
    addLetters(shuffled);
    Form2->Label2->Hide();
    Form2->Edit4->Text = shuffled.c_str();
    Form2->Edit2->Text = "";
}

bool checkAnswer(string answer) {
	return (answer == word);
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
  : TForm(Owner)
{ Label4->Hide();
  Memo1->Clear();
  Button2->Hide();
  Edit4->Hide();
  Label3->Hide();
  Edit2->Hide();
  Label2->Hide();
  Edit3->Hide();
  Button3->Hide();
  Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void resetGame()
{  // Form2->Memo1->Clear();
	Form2-> Label1->Caption = "���� ��������";
 Form2 -> Memo1->Lines->Append("   ��� ���������, " + PlayerName +
  ": ���������� ��������� ����: " + kol + "; ����� ����: " + totalTime + " ��� ");
	guessedWords = 0;
	attemptsLeft = 3;
	totalTime = 0;
	kol=0;
   //Form2->  Memo1->Text = ("���� ���������");
	Form2->Button2->Hide();
	Form2->Label4->Hide();
	Form2->Edit4->Hide();
	Form2->Label3->Hide();
	Form2->Edit2-> Hide ();
	Form2->Label2->Hide();
	Form2->Edit3->Hide();
	Form2->Label5->Hide();
	Form2-> Button3->Show();
	Form2->Timer1->Enabled = false;
	Form2->Timer1->Tag = 0;
	availableWords.clear();
	startGame();
}
//---------------------------------------------------------------------------
void saveResult(int guessedWords, int totalTime, std::string name) {
  std::ofstream outFile("result.txt", std::ios::app);

  if (outFile.is_open()) {
	if (level==1){
	outFile << "������� 1�� || ";
	}
	{ if (level==2)
	outFile << "������� 2�� || ";
	}
	{ if (level==3)

	outFile << "������� 3�� || ";
	}
	outFile << "��� ������: " << name << ", || ";
	outFile << "���������� ��������� ����: " << kol << ", || ";
	outFile << "����� ����: " << totalTime << " ���.";
	outFile << std::endl;
	outFile.close();
	}
	else
	{
	Form1->Memo1->Text=("������ �������� �����!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  Label4->Show();

  Label3->Show();
  Edit2->Show();
  Label2->Show();
  Edit3->Show();
  Label5->Hide();
  Edit1->Hide();
  Button1->Hide();
  Button2->Show();
 Edit4->Show();
   PlayerName = Edit1->Text; // ��������� ��� ������ � ���������� ������
  Edit4->Text = "";
  startGame();
 Timer1->Enabled = true;
 Memo1->Text=("   ������� ����, "+PlayerName );
 Edit2->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{  Edit1->Clear();
   Memo1->Clear();
   Edit2->SetFocus();
  if (guessedWords < 4 || (guessedWords == 4 && attemptsLeft > 0)) // ���� ���� ��� �� �����������
  {
  AnsiString answer = Edit2->Text;
  Edit2->Text = "";

  if (checkAnswer(string(answer.c_str())))
  {
    guessedWords++; // ����������� ���������� ��������� ����
    kol++; // ����������� ���������� ��������� ���� �� 1
	Memo1->Text=("   ����� ������� �����!");

    if (guessedWords < 5) { // ���� ���� ��� ����������� �����, ��������� ����� �����
    startGame();
    }
    else { // ���� ��� ����� �������, ������� ���������� � ��������� �� � ����
    totalTime += Timer1->Tag; // ��������� ����� �� ��������� �����
    saveResult(guessedWords, totalTime, string(PlayerName.c_str()));
       resetGame();
    }
  }
  else // ���� ����� �� �������
  {
    if (attemptsLeft == 1) { // ���� ������� ������ ���
    AnsiString wordValue = word.c_str();
    Memo1->Text=("   ������� ����� ����: "+ wordValue);
        guessedWords++; // ��������� � ���������� �����


    if (guessedWords < 5) { // ��������� ����� ����� � ����� ������
          startGame();
    }
	else { // ���� ���� ��� �����������, ������� ��������� �� ��������� ����
      totalTime += Timer1->Tag; // ��������� ����� �� ��������� �����
	  saveResult(guessedWords, totalTime, string(PlayerName.c_str()));
	  resetGame();
    }
    }
    else { // ���� ������� ��� ����
    attemptsLeft--;
    Memo1->Text=("   ������������ �����. ����� ��� ��������� " +IntToStr(attemptsLeft-1) + " ���(�)");
    }
    if (attemptsLeft == 0) { // ���� ����� ����������� ��� �������
	AnsiString wordValue = word.c_str();
    Memo1->Text=("   ������� ����� ����: "+ wordValue);
    guessedWords++; // ��������� � ���������� �����
    //attemptsLeft = 2; // ���������� ���������� �������

    if (guessedWords < 5) { // ��������� ����� ����� � ����� ������
      startGame();
    }
    else { // ���� ��� ����� �������, ������� ���������� � ��������� �� � ����
      totalTime += Timer1->Tag; // ��������� ����� �� ��������� �����
      saveResult(guessedWords, totalTime, string(PlayerName.c_str()));
	   resetGame();
    }
    }
    }
  }
  else { // ���� ���� ��� �����������
  totalTime += Timer1->Tag; // ��������� ����� �� ��������� �����
  saveResult(guessedWords, totalTime, string(PlayerName.c_str()));
  }
  if (guessedWords == 5) { // ���� ��� ���� ���� �������, ���������� ����
       resetGame();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
  Timer1->Tag++;
  Edit3->Text = IntToStr(Timer1->Tag) + " ���. "  ;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
  Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N1Click(TObject *Sender)
{
Form1->Show();
Form2->Close();
resetGame();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	 Form1-> Show();
	 Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
   Form3->Show();
   Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
 words1 = loadWordsFromFile("words1.txt");
	words2 = loadWordsFromFile("words2.txt");
	words3 = loadWordsFromFile("words3.txt");
}
//---------------------------------------------------------------------------

