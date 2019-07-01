namespace SupaDupaPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Interface : public System::Windows::Forms::Form
	{		

	public:
		Interface(void)
		{
			InitializeComponent();
		}

	Color CurrentColor = Color::Blue;
	Point CurrentPoint;
	Point PreviousPoint;
	bool isPressed = false;
	bool eraserChoice = false;

	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::Button^  pen_Button;
	private: System::Windows::Forms::Button^  eraser_Button;
	private: System::Windows::Forms::Button^  clear_Button;
	private: System::Windows::Forms::NumericUpDown^  pen_Size;
	private: System::Windows::Forms::NumericUpDown^  eraser_Size;



		void InitializeComponent(void)
		{
			this->canvas = (gcnew System::Windows::Forms::PictureBox());
			this->pen_Button = (gcnew System::Windows::Forms::Button());
			this->eraser_Button = (gcnew System::Windows::Forms::Button());
			this->pen_Size = (gcnew System::Windows::Forms::NumericUpDown());
			this->eraser_Size = (gcnew System::Windows::Forms::NumericUpDown());
			this->clear_Button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pen_Size))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eraser_Size))->BeginInit();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::White;
			this->canvas->Location = System::Drawing::Point(13, 71);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(537, 299);
			this->canvas->TabIndex = 0;
			this->canvas->TabStop = false;
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseUp);
			// 
			// pen_Button
			// 
			this->pen_Button->BackColor = System::Drawing::Color::Plum;
			this->pen_Button->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pen_Button->Location = System::Drawing::Point(13, 12);
			this->pen_Button->Name = L"pen_Button";
			this->pen_Button->Size = System::Drawing::Size(47, 23);
			this->pen_Button->TabIndex = 1;
			this->pen_Button->Text = L"Pen";
			this->pen_Button->UseVisualStyleBackColor = false;
			this->pen_Button->Click += gcnew System::EventHandler(this, &Interface::penClick);
			// 
			// eraser_Button
			// 
			this->eraser_Button->BackColor = System::Drawing::Color::Plum;
			this->eraser_Button->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->eraser_Button->Location = System::Drawing::Point(13, 40);
			this->eraser_Button->Name = L"eraser_Button";
			this->eraser_Button->Size = System::Drawing::Size(47, 23);
			this->eraser_Button->TabIndex = 2;
			this->eraser_Button->Text = L"Eraser";
			this->eraser_Button->UseVisualStyleBackColor = false;
			this->eraser_Button->Click += gcnew System::EventHandler(this, &Interface::eraserClick);
			// 
			// pen_Size
			// 
			this->pen_Size->Location = System::Drawing::Point(66, 14);
			this->pen_Size->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->pen_Size->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->pen_Size->Name = L"pen_Size";
			this->pen_Size->Size = System::Drawing::Size(47, 20);
			this->pen_Size->TabIndex = 3;
			this->pen_Size->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// eraser_Size
			// 
			this->eraser_Size->Location = System::Drawing::Point(66, 42);
			this->eraser_Size->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->eraser_Size->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->eraser_Size->Name = L"eraser_Size";
			this->eraser_Size->Size = System::Drawing::Size(47, 20);
			this->eraser_Size->TabIndex = 4;
			this->eraser_Size->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// clear_Button
			// 
			this->clear_Button->BackColor = System::Drawing::Color::Plum;
			this->clear_Button->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clear_Button->Location = System::Drawing::Point(476, 12);
			this->clear_Button->Name = L"clear_Button";
			this->clear_Button->Size = System::Drawing::Size(75, 51);
			this->clear_Button->TabIndex = 5;
			this->clear_Button->Text = L"Clear";
			this->clear_Button->UseVisualStyleBackColor = false;
			this->clear_Button->Click += gcnew System::EventHandler(this, &Interface::clearClick);
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PapayaWhip;
			this->ClientSize = System::Drawing::Size(561, 380);
			this->Controls->Add(this->clear_Button);
			this->Controls->Add(this->eraser_Size);
			this->Controls->Add(this->pen_Size);
			this->Controls->Add(this->eraser_Button);
			this->Controls->Add(this->pen_Button);
			this->Controls->Add(this->canvas);
			this->Name = L"Interface";
			this->Text = L"Interface";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pen_Size))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eraser_Size))->EndInit();
			this->ResumeLayout(false);

		}

		void paint() {
			if (eraserChoice) {
				int eraserSize;
				eraserSize = Convert::ToInt32(eraser_Size->Value);
				Pen^ eraser = gcnew Pen(CurrentColor, eraserSize);
				Graphics^ a = canvas->CreateGraphics();
				a->DrawLine(eraser, PreviousPoint, CurrentPoint);
			}
			else {
				int penSize;
				penSize = Convert::ToInt32(pen_Size->Value);
				Pen^ pen = gcnew Pen(CurrentColor, penSize);
				Graphics^ a = canvas->CreateGraphics();
				a->DrawLine(pen, PreviousPoint, CurrentPoint);
			}
		}

		private: System::Void penClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Blue;
			eraserChoice = false;
		}

		private: System::Void eraserClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::White;
			eraserChoice = true;
		}

		private: System::Void clearClick(System::Object^  sender, System::EventArgs^  e) {
			canvas->Refresh();
		}

		private: System::Void canvas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			isPressed = false;
		}

		private: System::Void canvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			isPressed = true;
			CurrentPoint = e->Location;
		}

		private: System::Void canvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (isPressed) {
				PreviousPoint = CurrentPoint;
				CurrentPoint = e->Location;
				paint();
			}
		}
	};
}
