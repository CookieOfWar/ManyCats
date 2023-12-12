#pragma once
namespace ManyCats {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Thurston
	/// </summary>
	public ref class Thurston : public System::Windows::Forms::Form
	{
	public:
		Thurston()
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Thurston()
		{
			if (components)
			{
				delete components;
			}
		}


	public:
		int moveX, moveY, moveSpeed = 50;

	private: 


	public: System::Windows::Forms::Timer^ ThurstonFirstMove;
	private: System::Windows::Forms::Button^ ThurstonScream;
	public:
	private:





	public:
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Thurston::typeid));
			this->ThurstonFirstMove = (gcnew System::Windows::Forms::Timer(this->components));
			this->ThurstonScream = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ThurstonFirstMove
			// 
			this->ThurstonFirstMove->Interval = 1;
			this->ThurstonFirstMove->Tick += gcnew System::EventHandler(this, &Thurston::ThurstonFirstMove_Tick);
			// 
			// ThurstonScream
			// 
			this->ThurstonScream->Location = System::Drawing::Point(219, 185);
			this->ThurstonScream->Name = L"ThurstonScream";
			this->ThurstonScream->Size = System::Drawing::Size(75, 23);
			this->ThurstonScream->TabIndex = 0;
			this->ThurstonScream->Text = L"MEAOW";
			this->ThurstonScream->UseVisualStyleBackColor = true;
			this->ThurstonScream->Click += gcnew System::EventHandler(this, &Thurston::ThurstonScream_Click);
			// 
			// Thurston
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Controls->Add(this->ThurstonScream);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Thurston";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Thurston";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ThurstonFirstMove_Tick(System::Object^ sender, System::EventArgs^ e) {
		if ((this->Location.X != 970) || (this->Location.Y != 290)) {
			this->Location = Point(this->Location.X + moveX, this->Location.Y + moveY);
		}
		else {
			ThurstonFirstMove->Stop();
			this->TopMost = true;
		}
	}
	public: System::Void ThurstonScream_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
