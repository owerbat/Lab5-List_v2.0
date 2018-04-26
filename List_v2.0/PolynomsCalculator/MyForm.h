#pragma once
#include "../List_v2.0/Polynom.h"

namespace PolynomsCalculator {

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
		TPolynom *p;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			p = new TPolynom[3];
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownZ;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownX;
	private: System::Windows::Forms::TextBox^  textBoxCoeff;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBoxCoeff = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(49, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(375, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(49, 245);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(375, 22);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(49, 390);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(375, 22);
			this->textBox3->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(484, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 58);
			this->button1->TabIndex = 3;
			this->button1->Text = L"ADD1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(613, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 58);
			this->button2->TabIndex = 4;
			this->button2->Text = L"CLEAR1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(484, 227);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 58);
			this->button3->TabIndex = 5;
			this->button3->Text = L"ADD2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(613, 227);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 58);
			this->button4->TabIndex = 6;
			this->button4->Text = L"CLEAR2";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(484, 371);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 58);
			this->button5->TabIndex = 7;
			this->button5->Text = L"RANDOM";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(77, 300);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 58);
			this->button6->TabIndex = 8;
			this->button6->Text = L"+";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(198, 300);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 58);
			this->button7->TabIndex = 9;
			this->button7->Text = L"-";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(324, 300);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 58);
			this->button8->TabIndex = 10;
			this->button8->Text = L"*";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(235, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Y^";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(355, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Z^";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(113, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 17);
			this->label1->TabIndex = 15;
			this->label1->Text = L"X^";
			// 
			// numericUpDownZ
			// 
			this->numericUpDownZ->Location = System::Drawing::Point(385, 31);
			this->numericUpDownZ->Name = L"numericUpDownZ";
			this->numericUpDownZ->Size = System::Drawing::Size(75, 22);
			this->numericUpDownZ->TabIndex = 14;
			// 
			// numericUpDownY
			// 
			this->numericUpDownY->Location = System::Drawing::Point(265, 31);
			this->numericUpDownY->Name = L"numericUpDownY";
			this->numericUpDownY->Size = System::Drawing::Size(75, 22);
			this->numericUpDownY->TabIndex = 13;
			// 
			// numericUpDownX
			// 
			this->numericUpDownX->Location = System::Drawing::Point(143, 31);
			this->numericUpDownX->Name = L"numericUpDownX";
			this->numericUpDownX->Size = System::Drawing::Size(75, 22);
			this->numericUpDownX->TabIndex = 12;
			// 
			// textBoxCoeff
			// 
			this->textBoxCoeff->Location = System::Drawing::Point(22, 31);
			this->textBoxCoeff->Name = L"textBoxCoeff";
			this->textBoxCoeff->Size = System::Drawing::Size(75, 22);
			this->textBoxCoeff->TabIndex = 11;
			this->textBoxCoeff->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 471);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDownZ);
			this->Controls->Add(this->numericUpDownY);
			this->Controls->Add(this->numericUpDownX);
			this->Controls->Add(this->textBoxCoeff);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		TMonom tmp(Convert::ToDouble(textBoxCoeff->Text), Convert::ToInt32(numericUpDownX->Text), 
				   Convert::ToInt32(numericUpDownY->Text), Convert::ToInt32(numericUpDownZ->Text));
		p[0].InsByOrder(tmp);
		textBox1->Text = GetStrPolynom(p[0]);
	}

	private: String^ GetStrMonom(TMonom &m) {
		if (!m.coeff) {
			return "";
		}

		String^ str = "(" + m.coeff + ")x^" + m.x + "y^" + m.y + "z^" + m.z;
		return str;
	}

	private: String^ GetStrPolynom(TPolynom &p) {
		if (!p.GetSize())
			return "0";

		String^ str = "";

		p.Reset();
		str += GetStrMonom(p.GetCurr()->value);
		p.GoNext();
		for (; !p.IsEnd(); p.GoNext()) {
			str += " + " + GetStrMonom(p.GetCurr()->value);
		}

		return str;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		TMonom tmp(Convert::ToDouble(textBoxCoeff->Text), Convert::ToInt32(numericUpDownX->Text),
			Convert::ToInt32(numericUpDownY->Text), Convert::ToInt32(numericUpDownZ->Text));
		p[1].InsByOrder(tmp);
		textBox2->Text = GetStrPolynom(p[1]);
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		while (p[0].GetSize()) {
			p[0].DelFirst();
		}
		textBox1->Text = GetStrPolynom(p[0]);
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		while (p[1].GetSize()) {
			p[1].DelFirst();
		}
		textBox2->Text = GetStrPolynom(p[1]);
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		//try {
			p[2] = p[0] + p[1];
			textBox3->Text = GetStrPolynom(p[2]);
		//}
		//catch (...) {

		//}
	}


	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		p[2] = p[0] - p[1];
		textBox3->Text = GetStrPolynom(p[2]);
	}

	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		p[2] = p[0] * p[1];
		textBox3->Text = GetStrPolynom(p[2]);
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		Random rand;

		textBoxCoeff->Text = Convert::ToString(rand.Next(100) - 50);
		numericUpDownX->Text = Convert::ToString(rand.Next(9));
		numericUpDownY->Text = Convert::ToString(rand.Next(9));
		numericUpDownZ->Text = Convert::ToString(rand.Next(9));
	}
};
}
