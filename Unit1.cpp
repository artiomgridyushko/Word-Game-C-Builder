//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Memo1->Clear();
Memo1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{  Form2->Memo1->Clear();
Form2->Label1->Hide();
  if(!(RadioButton1->Checked || RadioButton2->Checked || RadioButton3->Checked)){
	  Memo1->Show();
	  Memo1->Text= ("!�������� ���������� �������!");
   }
   else {
   Form2->Show();
   Form2->Edit1->Clear();
   Form2->Edit1->Show();
   Form2->Label5->Show();
   Form2->Button1->Show();
   Form2->Button3->Hide();

   Form2->Edit3->Clear();
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
Form3->Show();
Form3->Memo1->Clear();
   ifstream in("result.txt");
  string line;
  while (getline(in, line))
  {
   Form3->Memo1->Lines->Add(AnsiString(line.c_str()).c_str());
  }
  in.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
ShowMessage("��������� �������� ��������� ����� �� ������. "
			"��������� � ���� ��������� ��������� ����. "
			"������ ����� ������� � ������� �� �����. "
			"������ ������ � ������ ������� �� ���������� �����. "
			"���� �������� ��� ������: "
			"- �� 5 ���� (�������), "
			"- �� 5 �� 8 ���� (�������), "
			"- ����� 8 ���� (�������). "
			"�� ������ ������ ������ ��������������� ���� "
			"���� ��� ����������. ����� ����� ��������� �� "
			"������� ��� ����. "
			"�������� ����: ������, ����� � �����.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
  ShowMessage ("����������� ������ ���� ������� ������ ���-11 �������� ����");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	ShowMessage ("���� � ����� v1.0");
}
//---------------------------------------------------------------------------

