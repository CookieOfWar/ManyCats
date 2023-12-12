#pragma once
#include "Thurston.h"

namespace ManyCats {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для HUH
	/// </summary>
	public ref class HUH : public System::Windows::Forms::Form
	{
	public:
		static HUH^ instance;
		HUH(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			Location = Point(1500, -200);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HUH()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ FakeExit;

	protected:


	private:
		Media::SoundPlayer^ huhplayer = gcnew Media::SoundPlayer("E:/VSProjects/C++/ManyCats/Sounds/huh.wav");
		float moveX;
		float moveY;
		int moveSpeed = 50;


	private: System::Windows::Forms::Timer^ timerHuhFirst;
	private: System::ComponentModel::IContainer^ components;

	public:
		String^ test;
	public: System::Windows::Forms::Timer^ HUHAddThird;

	private:
		Thurston^ thur = gcnew Thurston();

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HUH::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->FakeExit = (gcnew System::Windows::Forms::Button());
			this->timerHuhFirst = (gcnew System::Windows::Forms::Timer(this->components));
			this->HUHAddThird = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(150, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 100);
			this->button1->TabIndex = 0;
			this->button1->Text = L"HUH\?";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HUH::button1_Click);
			// 
			// FakeExit
			// 
			this->FakeExit->BackColor = System::Drawing::Color::Red;
			this->FakeExit->FlatAppearance->BorderSize = 0;
			this->FakeExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FakeExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FakeExit->ForeColor = System::Drawing::Color::White;
			this->FakeExit->Location = System::Drawing::Point(438, 12);
			this->FakeExit->Name = L"FakeExit";
			this->FakeExit->Size = System::Drawing::Size(50, 50);
			this->FakeExit->TabIndex = 1;
			this->FakeExit->Text = L"X";
			this->FakeExit->UseVisualStyleBackColor = false;
			this->FakeExit->Click += gcnew System::EventHandler(this, &HUH::FakeExit_Click);
			// 
			// timerHuhFirst
			// 
			this->timerHuhFirst->Interval = 1;
			this->timerHuhFirst->Tick += gcnew System::EventHandler(this, &HUH::timerHuhFirst_Tick);
			// 
			// HUHAddThird
			// 
			this->HUHAddThird->Interval = 1;
			this->HUHAddThird->Tick += gcnew System::EventHandler(this, &HUH::HUHAddThird_Tick);
			// 
			// HUH
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Controls->Add(this->FakeExit);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"HUH";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HUH";
			this->TopMost = true;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FakeExit_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Выхода нет...", "Не-а", MessageBoxButtons::OK);
		FakeExit->Hide();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		huhplayer->Play();
		button1->Enabled = false;
		moveX = (450 - this->Location.X) / moveSpeed;
		moveY = (290 - this->Location.Y) / moveSpeed;
		timerHuhFirst->Start();
		thur->Show();
		this->Focus();
		thur->moveX = (970 - thur->Location.X) / thur->moveSpeed;
		thur->moveY = (290 - thur->Location.Y) / thur->moveSpeed;
		thur->ThurstonFirstMove->Start();
	}
	private: System::Void timerHuhFirst_Tick(System::Object^ sender, System::EventArgs^ e) {
		if ((this->Location.X != 450) || (this->Location.Y != 290)) {
			this->Location = Point(this->Location.X + moveX, this->Location.Y + moveY);
		}
		else {
			timerHuhFirst->Stop();
		}
	}


	private: System::Void HUHAddThird_Tick(System::Object^ sender, System::EventArgs^ e) {
		HUHAddThird->Stop();
	}
	
	};
}
