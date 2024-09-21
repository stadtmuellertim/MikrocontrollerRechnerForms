#pragma once

// Exclude not needed header files when including Windows.h.
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <string>

#include "SerialPort.h"
#include "ResultCache.h"

namespace MikrocontrollerRechnerFormsProject 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1 (SerialPort* comPort, ResultCache* results)
		{
			InitializeComponent();
			
			// Taking over pointers from unmanaged classes initialized in the main function.
			// Otherwise can't be accessed from this managed class.
			// ->
			// garbage collected heap / managed heap
			// vs.
			// native heap / unmanaged heap
			this->comPort = comPort;
			this->results = results;
		}
	protected:
		~Form1()
		{
			this->comPort->close();

			if (components)
				delete components;
		}
	private:
		SerialPort* comPort;
		ResultCache* results;

	private:
		System::Windows::Forms::Button^ zeroButton;
		System::Windows::Forms::Button^ threeButton;
		System::Windows::Forms::Button^ twoButton;
		System::Windows::Forms::Button^ oneButton;
		System::Windows::Forms::Button^ sixButton;
		System::Windows::Forms::Button^ fiveButton;
		System::Windows::Forms::Button^ fourButton;
		System::Windows::Forms::Button^ nineButton;
		System::Windows::Forms::Button^ eightButton;
		System::Windows::Forms::Button^ sevenButton;

		System::Windows::Forms::Button^ divideSignButton;
		System::Windows::Forms::Button^ multiplySignButton;
		System::Windows::Forms::Button^ minusSignButton;
		System::Windows::Forms::Button^ plusSignButton;

		System::Windows::Forms::Button^ backspaceSignButton;
		System::Windows::Forms::Button^ clearButton;
		System::Windows::Forms::Button^ saveButton;
		System::Windows::Forms::Button^ equalsSignButton;

		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ dateiToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ speichernToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ speichernUnterToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ beendenToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ gerätToolStripMenuItem;

		System::Windows::Forms::Label^ resultLabel;

		System::Windows::Forms::RadioButton^ connectionIndicator;
		System::Windows::Forms::Label^ outputFileInfolabel;

		System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	private:
		void InitializeComponent(void)
		{
			this->zeroButton = (gcnew System::Windows::Forms::Button());
			this->oneButton = (gcnew System::Windows::Forms::Button());
			this->twoButton = (gcnew System::Windows::Forms::Button());
			this->threeButton = (gcnew System::Windows::Forms::Button());
			this->fourButton = (gcnew System::Windows::Forms::Button());
			this->fiveButton = (gcnew System::Windows::Forms::Button());
			this->sixButton = (gcnew System::Windows::Forms::Button());
			this->sevenButton = (gcnew System::Windows::Forms::Button());
			this->eightButton = (gcnew System::Windows::Forms::Button());
			this->nineButton = (gcnew System::Windows::Forms::Button());
			this->plusSignButton = (gcnew System::Windows::Forms::Button());
			this->minusSignButton = (gcnew System::Windows::Forms::Button());
			this->multiplySignButton = (gcnew System::Windows::Forms::Button());
			this->divideSignButton = (gcnew System::Windows::Forms::Button());
			this->backspaceSignButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->equalsSignButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernUnterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->beendenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gerätToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->connectionIndicator = (gcnew System::Windows::Forms::RadioButton());
			this->outputFileInfolabel = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// zeroButton
			// 
			this->zeroButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zeroButton->Location = System::Drawing::Point(78, 404);
			this->zeroButton->Name = L"zeroButton";
			this->zeroButton->Size = System::Drawing::Size(60, 60);
			this->zeroButton->TabIndex = 0;
			this->zeroButton->Text = L"0";
			this->zeroButton->UseVisualStyleBackColor = true;
			this->zeroButton->Click += gcnew System::EventHandler(this, &Form1::zeroButton_Click);
			// 
			// oneButton
			// 
			this->oneButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oneButton->Location = System::Drawing::Point(12, 338);
			this->oneButton->Name = L"oneButton";
			this->oneButton->Size = System::Drawing::Size(60, 60);
			this->oneButton->TabIndex = 3;
			this->oneButton->Text = L"1";
			this->oneButton->UseVisualStyleBackColor = true;
			this->oneButton->Click += gcnew System::EventHandler(this, &Form1::oneButton_Click);
			// 
			// twoButton
			// 
			this->twoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->twoButton->Location = System::Drawing::Point(78, 338);
			this->twoButton->Name = L"twoButton";
			this->twoButton->Size = System::Drawing::Size(60, 60);
			this->twoButton->TabIndex = 2;
			this->twoButton->Text = L"2";
			this->twoButton->UseVisualStyleBackColor = true;
			this->twoButton->Click += gcnew System::EventHandler(this, &Form1::twoButton_Click);
			// 
			// threeButton
			// 
			this->threeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->threeButton->Location = System::Drawing::Point(144, 338);
			this->threeButton->Name = L"threeButton";
			this->threeButton->Size = System::Drawing::Size(60, 60);
			this->threeButton->TabIndex = 1;
			this->threeButton->Text = L"3";
			this->threeButton->UseVisualStyleBackColor = true;
			this->threeButton->Click += gcnew System::EventHandler(this, &Form1::threeButton_Click);
			// 
			// fourButton
			// 
			this->fourButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fourButton->Location = System::Drawing::Point(12, 272);
			this->fourButton->Name = L"fourButton";
			this->fourButton->Size = System::Drawing::Size(60, 60);
			this->fourButton->TabIndex = 6;
			this->fourButton->Text = L"4";
			this->fourButton->UseVisualStyleBackColor = true;
			this->fourButton->Click += gcnew System::EventHandler(this, &Form1::fourButton_Click);
			// 
			// fiveButton
			// 
			this->fiveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fiveButton->Location = System::Drawing::Point(78, 272);
			this->fiveButton->Name = L"fiveButton";
			this->fiveButton->Size = System::Drawing::Size(60, 60);
			this->fiveButton->TabIndex = 5;
			this->fiveButton->Text = L"5";
			this->fiveButton->UseVisualStyleBackColor = true;
			this->fiveButton->Click += gcnew System::EventHandler(this, &Form1::fiveButton_Click);
			// 
			// sixButton
			// 
			this->sixButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sixButton->Location = System::Drawing::Point(144, 272);
			this->sixButton->Name = L"sixButton";
			this->sixButton->Size = System::Drawing::Size(60, 60);
			this->sixButton->TabIndex = 4;
			this->sixButton->Text = L"6";
			this->sixButton->UseVisualStyleBackColor = true;
			this->sixButton->Click += gcnew System::EventHandler(this, &Form1::sixButton_Click);
			// 
			// sevenButton
			// 
			this->sevenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sevenButton->Location = System::Drawing::Point(12, 206);
			this->sevenButton->Name = L"sevenButton";
			this->sevenButton->Size = System::Drawing::Size(60, 60);
			this->sevenButton->TabIndex = 9;
			this->sevenButton->Text = L"7";
			this->sevenButton->UseVisualStyleBackColor = true;
			this->sevenButton->Click += gcnew System::EventHandler(this, &Form1::sevenButton_Click);
			// 
			// eightButton
			// 
			this->eightButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eightButton->Location = System::Drawing::Point(78, 206);
			this->eightButton->Name = L"eightButton";
			this->eightButton->Size = System::Drawing::Size(60, 60);
			this->eightButton->TabIndex = 8;
			this->eightButton->Text = L"8";
			this->eightButton->UseVisualStyleBackColor = true;
			this->eightButton->Click += gcnew System::EventHandler(this, &Form1::eightButton_Click);
			// 
			// nineButton
			// 
			this->nineButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nineButton->Location = System::Drawing::Point(144, 206);
			this->nineButton->Name = L"nineButton";
			this->nineButton->Size = System::Drawing::Size(60, 60);
			this->nineButton->TabIndex = 7;
			this->nineButton->Text = L"9";
			this->nineButton->UseVisualStyleBackColor = true;
			this->nineButton->Click += gcnew System::EventHandler(this, &Form1::nineButton_Click);
			// 
			// plusSignButton
			// 
			this->plusSignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plusSignButton->Location = System::Drawing::Point(239, 404);
			this->plusSignButton->Name = L"plusSignButton";
			this->plusSignButton->Size = System::Drawing::Size(95, 60);
			this->plusSignButton->TabIndex = 15;
			this->plusSignButton->Text = L"+";
			this->plusSignButton->UseVisualStyleBackColor = true;
			this->plusSignButton->Click += gcnew System::EventHandler(this, &Form1::plusSignButton_Click);
			// 
			// minusSignButton
			// 
			this->minusSignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minusSignButton->Location = System::Drawing::Point(239, 338);
			this->minusSignButton->Name = L"minusSignButton";
			this->minusSignButton->Size = System::Drawing::Size(95, 60);
			this->minusSignButton->TabIndex = 14;
			this->minusSignButton->Text = L"-";
			this->minusSignButton->UseVisualStyleBackColor = true;
			this->minusSignButton->Click += gcnew System::EventHandler(this, &Form1::minusSignButton_Click);
			// 
			// multiplySignButton
			// 
			this->multiplySignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->multiplySignButton->Location = System::Drawing::Point(239, 272);
			this->multiplySignButton->Name = L"multiplySignButton";
			this->multiplySignButton->Size = System::Drawing::Size(95, 60);
			this->multiplySignButton->TabIndex = 13;
			this->multiplySignButton->Text = L"x";
			this->multiplySignButton->UseVisualStyleBackColor = true;
			this->multiplySignButton->Click += gcnew System::EventHandler(this, &Form1::multiplySignButton_Click);
			// 
			// divideSignButton
			// 
			this->divideSignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->divideSignButton->Location = System::Drawing::Point(239, 206);
			this->divideSignButton->Name = L"divideSignButton";
			this->divideSignButton->Size = System::Drawing::Size(95, 60);
			this->divideSignButton->TabIndex = 12;
			this->divideSignButton->Text = L"÷";
			this->divideSignButton->UseVisualStyleBackColor = true;
			this->divideSignButton->Click += gcnew System::EventHandler(this, &Form1::divideSignButton_Click);
			// 
			// backspaceSignButton
			// 
			this->backspaceSignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->backspaceSignButton->Location = System::Drawing::Point(368, 206);
			this->backspaceSignButton->Name = L"backspaceSignButton";
			this->backspaceSignButton->Size = System::Drawing::Size(95, 60);
			this->backspaceSignButton->TabIndex = 16;
			this->backspaceSignButton->Text = L"⌫";
			this->backspaceSignButton->UseVisualStyleBackColor = true;
			this->backspaceSignButton->Click += gcnew System::EventHandler(this, &Form1::backspaceSignButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearButton->Location = System::Drawing::Point(368, 272);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(95, 60);
			this->clearButton->TabIndex = 17;
			this->clearButton->Text = L"C";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveButton->Location = System::Drawing::Point(368, 338);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(95, 60);
			this->saveButton->TabIndex = 18;
			this->saveButton->Text = L"Speichern";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// equalsSignButton
			// 
			this->equalsSignButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->equalsSignButton->Location = System::Drawing::Point(368, 404);
			this->equalsSignButton->Name = L"equalsSignButton";
			this->equalsSignButton->Size = System::Drawing::Size(95, 60);
			this->equalsSignButton->TabIndex = 19;
			this->equalsSignButton->Text = L"=";
			this->equalsSignButton->UseVisualStyleBackColor = true;
			this->equalsSignButton->Click += gcnew System::EventHandler(this, &Form1::equalsSignButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dateiToolStripMenuItem,
					this->gerätToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(475, 28);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->speichernToolStripMenuItem,
					this->speichernUnterToolStripMenuItem, this->beendenToolStripMenuItem
			});
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(59, 26);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::speichernToolStripMenuItem_Click);
			// 
			// speichernUnterToolStripMenuItem
			// 
			this->speichernUnterToolStripMenuItem->Name = L"speichernUnterToolStripMenuItem";
			this->speichernUnterToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->speichernUnterToolStripMenuItem->Text = L"Speichern unter...";
			this->speichernUnterToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::speichernUnterToolStripMenuItem_Click);
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->beendenToolStripMenuItem->Text = L"Beenden";
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::beendenToolStripMenuItem_Click);
			// 
			// gerätToolStripMenuItem
			// 
			this->gerätToolStripMenuItem->Name = L"gerätToolStripMenuItem";
			this->gerätToolStripMenuItem->Size = System::Drawing::Size(59, 26);
			this->gerätToolStripMenuItem->Text = L"Gerät";
			this->gerätToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::gerätToolStripMenuItem_DropDownOpening);
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultLabel->Location = System::Drawing::Point(12, 143);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(0, 32);
			this->resultLabel->TabIndex = 11;
			// 
			// connectionIndicator
			// 
			this->connectionIndicator->AutoSize = true;
			this->connectionIndicator->BackColor = System::Drawing::SystemColors::Control;
			this->connectionIndicator->Enabled = false;
			this->connectionIndicator->ForeColor = System::Drawing::SystemColors::ControlText;
			this->connectionIndicator->Location = System::Drawing::Point(12, 48);
			this->connectionIndicator->Name = L"connectionIndicator";
			this->connectionIndicator->Size = System::Drawing::Size(128, 20);
			this->connectionIndicator->TabIndex = 20;
			this->connectionIndicator->Text = L"Nicht verbunden.";
			this->connectionIndicator->UseVisualStyleBackColor = false;
			// 
			// outputFileInfolabel
			// 
			this->outputFileInfolabel->AutoSize = true;
			this->outputFileInfolabel->Location = System::Drawing::Point(15, 87);
			this->outputFileInfolabel->Name = L"outputFileInfolabel";
			this->outputFileInfolabel->Size = System::Drawing::Size(219, 16);
			this->outputFileInfolabel->TabIndex = 21;
			this->outputFileInfolabel->Text = L"Ausgabedatei: [Klick auf Speichern]";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 483);
			this->Controls->Add(this->outputFileInfolabel);
			this->Controls->Add(this->connectionIndicator);
			this->Controls->Add(this->equalsSignButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->backspaceSignButton);
			this->Controls->Add(this->plusSignButton);
			this->Controls->Add(this->minusSignButton);
			this->Controls->Add(this->multiplySignButton);
			this->Controls->Add(this->divideSignButton);
			this->Controls->Add(this->resultLabel);
			this->Controls->Add(this->sevenButton);
			this->Controls->Add(this->eightButton);
			this->Controls->Add(this->nineButton);
			this->Controls->Add(this->fourButton);
			this->Controls->Add(this->fiveButton);
			this->Controls->Add(this->sixButton);
			this->Controls->Add(this->oneButton);
			this->Controls->Add(this->twoButton);
			this->Controls->Add(this->threeButton);
			this->Controls->Add(this->zeroButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Mikrocontroller Rechner";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Input button click handler section
	private:
		// Decide wether to add or clear before adding the symbol to the result label.
		// Allows user to either continue with interim result
		// or start new expression if last result was an error message or 
		// a floating point number.
		// Either would contain a period character.
		void clearIfError(String^ symbol)
		{
			if (this->resultLabel->Text->Contains("."))
				this->resultLabel->Text = symbol;
			else
				this->resultLabel->Text += symbol;
		}
	private:
		System::Void zeroButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("0");
		}
		System::Void oneButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("1");
		}
		System::Void twoButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("2");
		}
		System::Void threeButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("3");
		}
		System::Void fourButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("4");
		}
		System::Void fiveButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("5");
		}
		System::Void sixButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("6");
		}
		System::Void sevenButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("7");
		}
		System::Void eightButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("8");
		}
		System::Void nineButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("9");
		}


		System::Void divideSignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("/");
		}
		System::Void multiplySignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("*");
		}
		System::Void minusSignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("-");
		}
		System::Void plusSignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			clearIfError("+");
		}

		System::Void backspaceSignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if(this->resultLabel->Text->Length > 0)
				this->resultLabel->Text = this->resultLabel->Text->
						Substring(0, this->resultLabel->Text->Length - 1);
		}
		System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->resultLabel->Text = "";
			this->results->clearCache();
		}
		System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Save all buffered communication.
			// Show file dialog if the output file is not yet set.
			if (!this->results->isFileNameSet())
				this->saveFileDialog1->ShowDialog();
			else
				this->results->saveToFile();
		}
		System::Void equalsSignButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Do nothing if no device is connected or if there is no input available.
			// All other expressions will be transmitted and errors are processed by the
			// microcontroller device itself.
			if (!this->comPort->isConnected() || this->resultLabel->Text == "")
				return;

			// Get the user input expression from resultLabel.
			// Add '\n' terminator and convert System::String^ to std::string.
			std::string expression = 
				msclr::interop::marshal_as<std::string>(this->resultLabel->Text + "\n");
			
			// Write to COM port and result cache.
			this->comPort->write(expression);
			this->results->appendExpression(expression);
			
			// Read COM port. Timeout after 2 seconds.
			// Append to result cache.
			std::string result = this->comPort->read();
			this->results->appendExpression(result + "\n");

			// Display result.
			this->resultLabel->Text = gcnew String(result.c_str());
		}

#pragma endregion

#pragma region Menu strip event handler
	private:
		// --- Item "Datei" ---
		System::Void speichernToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			saveButton->PerformClick();
		}
		System::Void speichernUnterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->saveFileDialog1->ShowDialog();
		}
		System::Void beendenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->comPort->close();
			Application::Exit();
		}


		// --- Item "Gerät" ---

		// When the menu strip item is clicked and the dropdown opens
		// find a list of available COM Port devices and add them
		// to the drop down menu item list.
		// Called only when the "Geräte" menu strip item is clicked.
		System::Void gerätToolStripMenuItem_DropDownOpening(System::Object^ sender, System::EventArgs^ e)
		{
			// Find out to which device comPort is currently connected.
			System::String^ connectedDevice = gcnew String(this->comPort->deviceName().c_str());
			bool foundAnyDevices = false;
			bool foundConnectedDevice = false;

			// Clear device list in the menu strip.
			gerätToolStripMenuItem->DropDownItems->Clear();

			// Buffer to store COM port paths.
			wchar_t lpTargetPath[5000];

			// Trying all possible port names from 0 to 255.
			for (int i = 0; i < 255; i++)
			{
				// QueryDosDevice() requires LPCWSTR so std::wstring is used.
				std::wstring deviceName = L"COM" + std::to_wstring(i);
				DWORD deviceExists = QueryDosDevice(deviceName.c_str(), lpTargetPath, 5000);

				// QueryDosDevice returns 0 if no devices are found
				if (!deviceExists == 0)
				{
					foundAnyDevices = true;

					// Add a new element to the menu strip drop down list.
					// Click on this element will connect to the device.
					System::String^ deviceName = gcnew String("COM" + i);
					ToolStripMenuItem^ deviceItem = gcnew ToolStripMenuItem();
					deviceItem->Text = deviceName;
					deviceItem->Click += gcnew EventHandler(this, &Form1::deviceSelectedHandler);
					gerätToolStripMenuItem->DropDownItems->Add(deviceItem);

					// Make the entry appear checked if the device is the
					// currently connected device.
					if (connectedDevice == deviceName)
					{
						foundConnectedDevice = true;

						deviceItem->Checked = true;
						deviceItem->Text += " [Trennen]";
					}
				}
			}

			// The previosly connected device was not found anymore.
			if (!foundConnectedDevice)
			{
				// Close COM port connection if there was one.
				this->comPort->close();

				// Update connection indicator.
				this->connectionIndicator->Checked = false;
				this->connectionIndicator->Text = "Nicht verbunden.";

				// No other devices were found either.
				if (!foundAnyDevices)
				{
					// Add info element in menu strip drop down list.
					ToolStripMenuItem^ noDeviceItem = (gcnew ToolStripMenuItem());
					noDeviceItem->Text = "Keine Geräte gefunden.";
					gerätToolStripMenuItem->DropDownItems->Add(noDeviceItem);
				}
			}
		}

#pragma endregion

#pragma region Other event handler
	private:
		// Click event handler for COM devices in the menu strip.
		// User selected new device.
		// Try to connect to the device given by sender and refresh status indicator.
		// Handles click event on a device item in the "Gerät" menu strip.
		void deviceSelectedHandler(Object^ sender, EventArgs^ e)
		{
			// UI drawing is done parallel to the handler execution.
			// Label needs to be manually refreshed in order to show the correct
			// text before going into comPort->connect(). If the device doesn't
			// answer right away the text will not show correctly.
			this->connectionIndicator->Text = "Verbinde...";
			this->connectionIndicator->Refresh();

			// Obtain the selected item from the argument to access its properties.
			ToolStripMenuItem^ item = (ToolStripMenuItem^)sender;

			// Convert the selected item device name of type System::String^ to std::string.
			// Use substring to only get the first 4 characters in the device name String.
			std::string selectedDevice =
				msclr::interop::marshal_as<std::string>(item->Text->Substring(0, 4));

			// Try connecting to the selected device.
			// comPort->connect() returns an error message if connection failed
			// or firmware info if the connected device is running correctly.
			System::String^ connectionErrorMsg =
				gcnew String(this->comPort->connect(selectedDevice).c_str());
			this->connectionIndicator->Text = connectionErrorMsg;
			this->connectionIndicator->Checked = this->comPort->isConnected();
		}

		System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			std::string fileName = msclr::interop::marshal_as<std::string>(this->saveFileDialog1->FileName);
			this->results->setFileName(fileName);
			this->outputFileInfolabel->Text = "Ausgabedatei: " + this->saveFileDialog1->FileName;
			this->results->saveToFile();
		}

		System::Void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			this->comPort->close();
		}

	// Overriding ProcessCmdKey.
	// Catch all upcoming keyboard inputs and process them.
	protected:
		bool ProcessCmdKey(System::Windows::Forms::Message% msg, System::Windows::Forms::Keys keyData) override
		{
			// Check if the pressed key is a valid keyboard input.
			// Perform a click on the corresponding button on the form.

			// Digits {0...9} on keyboard and num pad.
			if (keyData == Keys::D0 || keyData == Keys::NumPad0)
				this->zeroButton->PerformClick();
			else if (keyData == Keys::D1 || keyData == Keys::NumPad1)
				this->oneButton->PerformClick();
			else if (keyData == Keys::D2 || keyData == Keys::NumPad2)
				this->twoButton->PerformClick();
			else if (keyData == Keys::D3 || keyData == Keys::NumPad3)
				this->threeButton->PerformClick();
			else if (keyData == Keys::D4 || keyData == Keys::NumPad4)
				this->fourButton->PerformClick();
			else if (keyData == Keys::D5 || keyData == Keys::NumPad5)
				this->fiveButton->PerformClick();
			else if (keyData == Keys::D6 || keyData == Keys::NumPad6)
				this->sixButton->PerformClick();
			else if (keyData == Keys::D7 || keyData == Keys::NumPad7)
				this->sevenButton->PerformClick();
			else if (keyData == Keys::D8 || keyData == Keys::NumPad8)
				this->eightButton->PerformClick();
			else if (keyData == Keys::D9 || keyData == Keys::NumPad9)
				this->nineButton->PerformClick();

			// Operator symbols {+-*/}
			else if (keyData == Keys::Oemplus || keyData == Keys::Add)
				this->plusSignButton->PerformClick();
			else if (keyData == Keys::OemMinus || keyData == Keys::Subtract)
				this->minusSignButton->PerformClick();
			else if (keyData == (Keys::Oemplus | Keys::Shift) || keyData == Keys::Multiply)
				this->multiplySignButton->PerformClick();
			else if (keyData == (Keys::D7 | Keys::Shift) || keyData == Keys::Divide)
				this->divideSignButton->PerformClick();

			// Conrol keys {Backspace, Enter, Esc}
			else if (keyData == Keys::Back)
				this->backspaceSignButton->PerformClick();
			else if (keyData == Keys::Escape)
				this->clearButton->PerformClick();
			else if (keyData == Keys::Enter)
				this->equalsSignButton->PerformClick();

			// Returning true will suppress any other
			// succeeding processing of the key press event.
			return true;
		}
#pragma endregion

	}; // class Form1
} // namespace MikrocontrollerRechnerFormsProject
