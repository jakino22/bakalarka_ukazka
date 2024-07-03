#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Prefix.h"
#include "Translator.h"
#include "dpll.h"
#include "WalkSat.h"
#include <chrono>
#include <msclr\marshal_cppstd.h>


#pragma execution_character_set( "utf-8" )


namespace baka1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int phase = 1;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;

	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label17;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label20;


	protected:








	protected:



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zadajte pravidlá vašej logiky";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(12, 39);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(375, 577);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(393, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Pravidlá zadávania logiky";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(393, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Logiku zapisujte nasledovne:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(393, 86);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"*názov logiky*";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(393, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(221, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"*pravdivostné hodnoty vašej logiky*";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(393, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 16);
			this->label6->TabIndex = 6;
			this->label6->Text = L"*unárne spojky*";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(393, 134);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 16);
			this->label7->TabIndex = 7;
			this->label7->Text = L"*binárne spojky*";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(397, 239);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 16);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Načítaj vzor:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(396, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 28);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Heyting’s logic";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(396, 292);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 29);
			this->button2->TabIndex = 10;
			this->button2->Text = L"First Order Logic";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(570, 573);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 43);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Ďalej";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(400, 573);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(107, 43);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Späť";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(393, 150);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 16);
			this->label9->TabIndex = 13;
			this->label9->Text = L"*prázdny riadok*";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(393, 166);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(277, 16);
			this->label10->TabIndex = 14;
			this->label10->Text = L"*n1 n2 (unárne spojky na n1) (binárne spojky)*";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(393, 182);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 16);
			this->label11->TabIndex = 15;
			this->label11->Text = L"...";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(393, 198);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(10, 16);
			this->label12->TabIndex = 16;
			this->label12->Text = L" ";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(393, 214);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(10, 16);
			this->label13->TabIndex = 17;
			this->label13->Text = L" ";
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(393, 230);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(10, 16);
			this->label14->TabIndex = 18;
			this->label14->Text = L" ";
			this->label14->Visible = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(393, 246);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(10, 16);
			this->label15->TabIndex = 19;
			this->label15->Text = L" ";
			this->label15->Visible = false;
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(68, 55);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(533, 333);
			this->textBox2->TabIndex = 20;
			this->textBox2->Text = L"Prebieha výpočet";
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(228, 442);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(215, 70);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Späť";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(396, 327);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(151, 29);
			this->button6->TabIndex = 22;
			this->button6->Text = L"Łukasiewicz’s logic";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(396, 362);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(151, 29);
			this->button7->TabIndex = 23;
			this->button7->Text = L"Kleene’s strong logic";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(396, 432);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(151, 29);
			this->button9->TabIndex = 25;
			this->button9->Text = L" Belnap’s logic";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(396, 397);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(151, 29);
			this->button10->TabIndex = 26;
			this->button10->Text = L"Kleene’s weak logic";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(393, 264);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(10, 16);
			this->label16->TabIndex = 27;
			this->label16->Text = L" ";
			this->label16->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(396, 524);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(135, 22);
			this->textBox3->TabIndex = 28;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(393, 505);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(208, 16);
			this->label17->TabIndex = 29;
			this->label17->Text = L"Vybrané hodnoty (formou x1,x2,...):";
			this->label17->Click += gcnew System::EventHandler(this, &MyForm::label17_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(397, 333);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(98, 16);
			this->label18->TabIndex = 31;
			this->label18->Text = L"Rieš pomocou:";
			this->label18->Visible = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(398, 361);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(109, 20);
			this->checkBox1->TabIndex = 32;
			this->checkBox1->Text = L"Signed-DPLL";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(398, 387);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(133, 20);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"regular-WalkSAT";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Visible = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(408, 469);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(87, 16);
			this->label19->TabIndex = 34;
			this->label19->Text = L"Cesta k teórií:";
			this->label19->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(505, 466);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(165, 22);
			this->textBox4->TabIndex = 35;
			this->textBox4->Visible = false;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(521, 494);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(132, 25);
			this->button8->TabIndex = 36;
			this->button8->Text = L"Načítaj teóriu";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(408, 447);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(225, 16);
			this->label20->TabIndex = 37;
			this->label20->Text = L"(napr.: D:\\\\priecinok\\\\mediumSAT.txt)";
			this->label20->Visible = false;
			this->label20->Click += gcnew System::EventHandler(this, &MyForm::label20_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 623);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"SAT solver";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void saveLogic() {
		std::ofstream logic("logic.txt");
		logic << toStandardString(textBox1->Text);
		logic.close();
		std::ofstream dv("dv.txt");
		dv << toStandardString(textBox3->Text);
		dv.close();
	}

	private: System::Void loadLogic(std::string l) {
		textBox1->Text = "";
		std::ifstream infile(l+".txt");
		std::string line;
		std::string text = "";
		std::getline(infile, line);
		text = line;
		std::getline(infile, line);
		text = text + "\r\n" + line;
		std::getline(infile, line);
		text = text + "\r\n" + line;
		std::getline(infile, line);
		text = text + "\r\n" + line + "\r\n";
		std::getline(infile, line);
		textBox1->Text = "";

		while (std::getline(infile, line)) {

			std::vector<std::string> split_line = split(line,' ');
			line = zarovnaj(split_line, 10);
			text = text + "\r\n" + line;

		}
		textBox1->Text = gcnew String(text.c_str());
	}

	private: System::Void saveCNF() {
		std::ofstream CNF("CNF.txt");
		CNF << toStandardString(textBox1->Text);
		CNF.close();
	}

	private: System::Void loadCNF() {
		textBox1->Text = "";
		std::ifstream infile("CNF.txt");
		std::string line;
		std::string text = "";
		textBox1->Text = "";
		while (std::getline(infile, line)) {
			if (text == "") {
				text = line;
			}
			else {
				text = text + "\r\n" + line;
			}
		}
		textBox1->Text = gcnew String(text.c_str());
	}

	private: std::vector<std::string> split(std::string line, char delim) {
		std::vector<std::string>split_line;
		std::string word = "";

		for (char c : line) {
			if (c == delim && word != "") {
				split_line.push_back(word);
				word = "";
			}
			else {
				if (c != '\n' && c != '\r' && c != delim) {
					word += c;
				}
			}
		}
		if (word != "") {
			split_line.push_back(word);
		}
		return split_line;
	}

	private: std::string zarovnaj(std::vector<std::string>input, int space_len) {
		std::string output = "";

		for (std::string word : input) {

			
			int space_num = space_len - word.length();
			if (word.find(".") != -1 || word.find("/") != -1) {
				space_num--;
			}

			if (output == "") {
				output = word;
				for (int i = 0; i < space_num; i++) {
					output += ' ';
				}
			}
			else {
				output += word;
				for (int i = 0; i < space_num; i++) {
					output += ' ';
				}
			}
		}
		return output;
	}

	static std::string toStandardString(System::String^ string)
		   {
			   using System::Runtime::InteropServices::Marshal;
			   System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			   char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			   std::string returnString(charPointer, string->Length);
			   Marshal::FreeHGlobal(pointer);

			   return returnString;
		   }

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (phase == 3) {
			return;
		}
		phase++;
		if (phase == 2) {
			saveLogic();
			loadCNF();
			label18->Visible = true;
			checkBox1->Visible = true;
			checkBox2->Visible = true;
			label17->Visible = false;
			textBox3->Visible = false;
			button4->Visible = true;
			button1->Visible = false;
			button2->Visible = false;
			button10->Visible = false;
			button9->Visible = false;
			button6->Visible = false;
			button7->Visible = false;
			label1->Text =  L"Zadajte teóriu vo vašej logike";
			label2->Text = L"Pravidlá zadávania teórie";
			label3->Text = L"Teóriu zadávame nasledovne:";
			label4->Text = L"Jednotlivé formule zadávame pod seba";
			label5->Text = L"Formula tvorená binárnou spojkou musí byť";
			label6->Text = L"vždy v zátvorke";
			label7->Text = L"a>b -> zlý zápis";
			label9->Text = L"(a>b) -> dobrý zápis";
			label10->Text = L"unárna spojka sa nachádza vždy pred";
			label11->Text = L"zátvorkou, unárna spojka premennej sa píše";
			label12->Text = L"bez zátvorky, teda ox je dobrý zápis,";
			label13->Text = L"ale o(x) nieje";
			label14->Visible = true;
			label14->Text = "";
			label15->Visible = true;
			label15->Text = "";
			label16->Text = L"zápis aX, kde X patrí N je zakázaný";
			label16->Visible = true;
			button3->Text = L"Zisti SAT";
			label8->Visible = false;
			button8->Visible = true;
			textBox4->Visible = true;
			label19->Visible = true;
			label20->Visible = true;
		}
		if (phase == 3) {
			saveCNF();
			label18->Visible = false;
			checkBox1->Visible = false;
			checkBox2->Visible = false;
			button3->Visible = false;
			button4->Visible = false;
			button10->Visible = false;
			button9->Visible = false;
			button6->Visible = false;
			button7->Visible = false;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
			label6->Visible = false;
			label7->Visible = false;
			label8->Visible = false;
			label9->Visible = false;
			label10->Visible = false;
			label11->Visible = false;
			label12->Visible = false;
			label13->Visible = false;
			label14->Visible = false;
			label15->Visible = false;
			label16->Visible = false;
			textBox1->Visible = false;
			button8->Visible = false;
			textBox4->Visible = false;
			label19->Visible = false;
			label20->Visible = false;

			textBox2->Visible = true;
			button5->Visible = true;


			Translator t("logic.txt");
			std::string text = "";

			if (checkBox1->CheckState == CheckState::Checked) {
				CNF cnf = t.translate("CNF.txt", "dv.txt");
				DPLL dpll = DPLL(t);
				auto start = std::chrono::high_resolution_clock::now();
				auto a = dpll.solve(cnf);
				auto finish = std::chrono::high_resolution_clock::now();
				auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
				text += "signed-DPLL: duration- ";
				text += std::to_string(microseconds.count());
				text += " ms\r\n";
				text += a;
				//textBox2->Text = gcnew String(a.c_str());
				if (a == "SAT") {
					dpll.compute_eval(cnf);
					for (const auto& v : dpll.bottom_vars) {
						text += "\r\n" + v + " = " + *dpll.evaluation_of_vars[v].begin();
					}
				}
				textBox2->Text = gcnew String(text.c_str());
			}
			if (checkBox2->CheckState == CheckState::Checked) {
				CNF cnf = t.regular_translate("CNF.txt", "dv.txt");
				WalkSat walksat;
				if (text != "") {
					text += "\r\n\r\n";
				}
				auto start = std::chrono::high_resolution_clock::now();
				auto a = walksat.Walk(10, 100, cnf,t);
				auto finish = std::chrono::high_resolution_clock::now();
				auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
				text += "WalkSAT: duration- ";
				text += std::to_string(microseconds.count());
				text += " ms\r\n";
				text += a;
				//textBox2->Text = gcnew String(a.c_str());
				if (a == "SAT") {
					for (auto var : walksat.bottom_vars) {
						text += "\r\n" + var + " = " + walksat.valuation[var];
					}
				}
				textBox2->Text = gcnew String(text.c_str());
			}
			if (checkBox1->CheckState != CheckState::Checked && checkBox2->CheckState != CheckState::Checked) {
				textBox2->Text = L"Nebol vybraný ani jeden spôsob riešenia";
			}
			
		}


	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		phase--;
		if (phase == 1) {
			saveCNF();
			loadLogic("logic");
			button8->Visible = false;
			textBox4->Visible = false;
			label19->Visible = false;
			label20->Visible = false;
			label18->Visible = false;
			checkBox1->Visible = false;
			checkBox2->Visible = false;
			button4->Visible = false;
			label8->Visible = true;
			button1->Visible = true;
			button2->Visible = true;
			button6->Visible = true;
			button7->Visible = true;
			button9->Visible = true;
			button10->Visible = true;
			label1->Text = L"Zadajte pravidlá vašej logiky";
			label2->Text = L"Pravidlá zadávania logiky";
			label3->Text = L"Logiku zapisujte nasledovne:";
			label4->Text = L"*názov logiky*";
			label5->Text = L"*pravdivostné hodnoty*";
			label6->Text = L"*unárne spojky*";
			label7->Text = L"*binárne spojky*";
			label9->Text = L"*prázdny riadok*";
			label10->Text = L"*n1 n2 (unárne spojky na n1) (binárne spojky)*";
			label11->Text = "";
			label12->Text = "";
			label13->Text = "";
			label14->Visible = false;
			label14->Text = "";
			label15->Visible = false;
			label15->Text = "";
			label16->Text = "";
			label17->Visible = true;
			textBox3->Visible = true;
			button3->Text = L"Ďalej";
		}

	}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {//ht
		loadLogic("ht");
		textBox3->Text = "1";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {//fol
		loadLogic("fol");
		textBox3->Text = "1";
	}
	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		phase--;
		loadCNF();
		label18->Visible = true;
		checkBox1->Visible = true;
		checkBox2->Visible = true;
		button3->Visible = true;
		button4->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		label5->Visible = true;
		label6->Visible = true;
		label7->Visible = true;
		label9->Visible = true;
		label10->Visible = true;
		label11->Visible = true;
		label12->Visible = true;
		label13->Visible = true;
		label14->Visible = true;
		label15->Visible = true;
		label16->Visible = true;
		textBox1->Visible = true;
		button8->Visible = true;
		textBox4->Visible = true;
		label19->Visible = true;
		label20->Visible = true;

		textBox2->Visible = false;
		button5->Visible = false;
		
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {//luk
	textBox3->Text = "1";
	loadLogic("lk");
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {//kleene
	loadLogic("kl");
	textBox3->Text = "1";
}

private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {//belnap
	loadLogic("belnap");
	textBox3->Text = "1";
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {//kleene w
	loadLogic("klw");
	textBox3->Text = "1";
}
private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = "";
	msclr::interop::marshal_context context;
	std::ifstream infile(context.marshal_as<std::string>(textBox4->Text));
	std::string line;
	std::string text = "";
	textBox1->Text = "";
	while (std::getline(infile, line)) {
		if (text == "") {
			text = line;
		}
		else {
			text = text + "\r\n" + line;
		}
	}
	textBox1->Text = gcnew String(text.c_str());
}
private: System::Void label20_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
