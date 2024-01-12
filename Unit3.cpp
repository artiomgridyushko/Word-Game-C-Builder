//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
using namespace std;

#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
 Memo1->ScrollBars = ssBoth;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::N1Click(TObject *Sender)
{
	Form1->Show();
	Form3->Close();
}
//---------------------------------------------------------------------------


