namespace SupaDupaPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum tools { pen = 1, eraser, rectangle, ellipse, stroke };

	public ref class Interface : public System::Windows::Forms::Form
	{		

	public:

		Interface(void)
		{
			InitializeComponent();
		}	

	Color CurrentColor = Color::Black;
	Point CurrentPoint;
	Point PreviousPoint;
	Point CurrentClearPoint;
	Point PreviousClearPoint;
	float width = 1;
	bool isPressed = false;
	int checkInstrument = 0;

	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::ToolStrip^  toolStripColor;
	private: System::Windows::Forms::ToolStripButton^  blackColorButton;
	private: System::Windows::Forms::ToolStripButton^  greyColorButton;
	private: System::Windows::Forms::ToolStripButton^  whiteColorButton;
	private: System::Windows::Forms::ToolStripButton^  redColorButton;
	private: System::Windows::Forms::ToolStripButton^  yellowColorButton;
	private: System::Windows::Forms::ToolStripButton^  greenColorButton;
	private: System::Windows::Forms::ToolStripButton^  blueColorButton;
	private: System::Windows::Forms::ToolStrip^  toolStripTools;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripButton^  rectangleButton;
	private: System::Windows::Forms::ToolStripButton^  ellipseButton;
	private: System::Windows::Forms::ToolStripButton^  strokeButton;
	private: System::Windows::Forms::ToolStripButton^  penButton;
	private: System::Windows::Forms::ToolStripButton^  eraserButton;
	private: System::Windows::Forms::ToolStripButton^  clearButton;
	private: System::Windows::Forms::ToolStripMenuItem^  widthOnePixel;
	private: System::Windows::Forms::ToolStripMenuItem^  widthEightPixels;
	private: System::Windows::Forms::ToolStripMenuItem^  widthFivePixels;
	private: System::Windows::Forms::ToolStripMenuItem^  widthThreePixels;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface::typeid));
			this->canvas = (gcnew System::Windows::Forms::PictureBox());
			this->toolStripColor = (gcnew System::Windows::Forms::ToolStrip());
			this->blackColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->greyColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->whiteColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->redColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->yellowColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->greenColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->blueColorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->widthOnePixel = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->widthThreePixels = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->widthFivePixels = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->widthEightPixels = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTools = (gcnew System::Windows::Forms::ToolStrip());
			this->rectangleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ellipseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->strokeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->penButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->eraserButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->clearButton = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->BeginInit();
			this->toolStripColor->SuspendLayout();
			this->toolStripTools->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->canvas->BackColor = System::Drawing::Color::White;
			this->canvas->Location = System::Drawing::Point(39, 6);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(477, 440);
			this->canvas->TabIndex = 0;
			this->canvas->TabStop = false;
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Interface::canvas_MouseUp);
			// 
			// toolStripColor
			// 
			this->toolStripColor->AutoSize = false;
			this->toolStripColor->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripColor->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStripColor->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->blackColorButton,
					this->greyColorButton, this->whiteColorButton, this->redColorButton, this->yellowColorButton, this->greenColorButton, this->blueColorButton,
					this->toolStripDropDownButton1
			});
			this->toolStripColor->Location = System::Drawing::Point(521, 0);
			this->toolStripColor->Name = L"toolStripColor";
			this->toolStripColor->Size = System::Drawing::Size(40, 450);
			this->toolStripColor->TabIndex = 10;
			this->toolStripColor->Text = L"toolStrip1";
			// 
			// blackColorButton
			// 
			this->blackColorButton->AutoSize = false;
			this->blackColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blackColorButton.BackgroundImage")));
			this->blackColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->blackColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->blackColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->blackColorButton->Name = L"blackColorButton";
			this->blackColorButton->Size = System::Drawing::Size(30, 30);
			this->blackColorButton->Click += gcnew System::EventHandler(this, &Interface::blackColorButtonClick);
			// 
			// greyColorButton
			// 
			this->greyColorButton->AutoSize = false;
			this->greyColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"greyColorButton.BackgroundImage")));
			this->greyColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->greyColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->greyColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->greyColorButton->Name = L"greyColorButton";
			this->greyColorButton->Size = System::Drawing::Size(30, 30);
			this->greyColorButton->Text = L"toolStripButton2";
			this->greyColorButton->Click += gcnew System::EventHandler(this, &Interface::greyColorButtonClick);
			// 
			// whiteColorButton
			// 
			this->whiteColorButton->AutoSize = false;
			this->whiteColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whiteColorButton.BackgroundImage")));
			this->whiteColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->whiteColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->whiteColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->whiteColorButton->Name = L"whiteColorButton";
			this->whiteColorButton->Size = System::Drawing::Size(30, 30);
			this->whiteColorButton->Text = L"toolStripButton7";
			this->whiteColorButton->Click += gcnew System::EventHandler(this, &Interface::whiteColorButtonClick);
			// 
			// redColorButton
			// 
			this->redColorButton->AutoSize = false;
			this->redColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"redColorButton.BackgroundImage")));
			this->redColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->redColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->redColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->redColorButton->Name = L"redColorButton";
			this->redColorButton->Size = System::Drawing::Size(30, 30);
			this->redColorButton->Text = L"toolStripButton3";
			this->redColorButton->Click += gcnew System::EventHandler(this, &Interface::redColorButtonClick);
			// 
			// yellowColorButton
			// 
			this->yellowColorButton->AutoSize = false;
			this->yellowColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"yellowColorButton.BackgroundImage")));
			this->yellowColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->yellowColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->yellowColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->yellowColorButton->Name = L"yellowColorButton";
			this->yellowColorButton->Size = System::Drawing::Size(30, 30);
			this->yellowColorButton->Text = L"toolStripButton5";
			this->yellowColorButton->Click += gcnew System::EventHandler(this, &Interface::yellowColorButtonClick);
			// 
			// greenColorButton
			// 
			this->greenColorButton->AutoSize = false;
			this->greenColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"greenColorButton.BackgroundImage")));
			this->greenColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->greenColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->greenColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->greenColorButton->Name = L"greenColorButton";
			this->greenColorButton->Size = System::Drawing::Size(30, 30);
			this->greenColorButton->Text = L"toolStripButton6";
			this->greenColorButton->Click += gcnew System::EventHandler(this, &Interface::greenColorButtonClick);
			// 
			// blueColorButton
			// 
			this->blueColorButton->AutoSize = false;
			this->blueColorButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blueColorButton.BackgroundImage")));
			this->blueColorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->blueColorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->blueColorButton->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->blueColorButton->Name = L"blueColorButton";
			this->blueColorButton->Size = System::Drawing::Size(30, 30);
			this->blueColorButton->Text = L"toolStripButton4";
			this->blueColorButton->Click += gcnew System::EventHandler(this, &Interface::blueColorButtonClick);
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->AutoSize = false;
			this->toolStripDropDownButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.BackgroundImage")));
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->widthOnePixel,
					this->widthThreePixels, this->widthFivePixels, this->widthEightPixels
			});
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(30, 30);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			// 
			// widthOnePixel
			// 
			this->widthOnePixel->AutoSize = false;
			this->widthOnePixel->BackColor = System::Drawing::SystemColors::Control;
			this->widthOnePixel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"widthOnePixel.BackgroundImage")));
			this->widthOnePixel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->widthOnePixel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->widthOnePixel->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->widthOnePixel->Name = L"widthOnePixel";
			this->widthOnePixel->Size = System::Drawing::Size(80, 20);
			this->widthOnePixel->Click += gcnew System::EventHandler(this, &Interface::widthOnePixelClick);
			// 
			// widthThreePixels
			// 
			this->widthThreePixels->AutoSize = false;
			this->widthThreePixels->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"widthThreePixels.BackgroundImage")));
			this->widthThreePixels->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->widthThreePixels->Name = L"widthThreePixels";
			this->widthThreePixels->Size = System::Drawing::Size(80, 20);
			this->widthThreePixels->Click += gcnew System::EventHandler(this, &Interface::widthThreePixelsClick);
			// 
			// widthFivePixels
			// 
			this->widthFivePixels->AutoSize = false;
			this->widthFivePixels->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"widthFivePixels.BackgroundImage")));
			this->widthFivePixels->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->widthFivePixels->Name = L"widthFivePixels";
			this->widthFivePixels->Size = System::Drawing::Size(80, 20);
			this->widthFivePixels->Click += gcnew System::EventHandler(this, &Interface::widthFivePixelsClick);
			// 
			// widthEightPixels
			// 
			this->widthEightPixels->AutoSize = false;
			this->widthEightPixels->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"widthEightPixels.BackgroundImage")));
			this->widthEightPixels->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->widthEightPixels->Name = L"widthEightPixels";
			this->widthEightPixels->Size = System::Drawing::Size(80, 20);
			this->widthEightPixels->Click += gcnew System::EventHandler(this, &Interface::widthEightPixelsClick);
			// 
			// toolStripTools
			// 
			this->toolStripTools->AutoSize = false;
			this->toolStripTools->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripTools->Dock = System::Windows::Forms::DockStyle::Left;
			this->toolStripTools->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->rectangleButton,
					this->ellipseButton, this->strokeButton, this->penButton, this->eraserButton, this->clearButton
			});
			this->toolStripTools->Location = System::Drawing::Point(0, 0);
			this->toolStripTools->Name = L"toolStripTools";
			this->toolStripTools->Size = System::Drawing::Size(35, 450);
			this->toolStripTools->TabIndex = 11;
			this->toolStripTools->Text = L"toolStrip2";
			// 
			// rectangleButton
			// 
			this->rectangleButton->AutoSize = false;
			this->rectangleButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rectangleButton.BackgroundImage")));
			this->rectangleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->rectangleButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->rectangleButton->Name = L"rectangleButton";
			this->rectangleButton->Size = System::Drawing::Size(20, 20);
			this->rectangleButton->Click += gcnew System::EventHandler(this, &Interface::rectangleButtonClick);
			// 
			// ellipseButton
			// 
			this->ellipseButton->AutoSize = false;
			this->ellipseButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ellipseButton.BackgroundImage")));
			this->ellipseButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ellipseButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ellipseButton->Name = L"ellipseButton";
			this->ellipseButton->Size = System::Drawing::Size(20, 20);
			this->ellipseButton->Text = L"toolStripButton2";
			this->ellipseButton->Click += gcnew System::EventHandler(this, &Interface::ellipseButtonClick);
			// 
			// strokeButton
			// 
			this->strokeButton->AutoSize = false;
			this->strokeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"strokeButton.BackgroundImage")));
			this->strokeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->strokeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->strokeButton->Name = L"strokeButton";
			this->strokeButton->Size = System::Drawing::Size(20, 20);
			this->strokeButton->Text = L"toolStripButton3";
			this->strokeButton->Click += gcnew System::EventHandler(this, &Interface::strokeButtonClick);
			// 
			// penButton
			// 
			this->penButton->AutoSize = false;
			this->penButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"penButton.BackgroundImage")));
			this->penButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->penButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->penButton->Name = L"penButton";
			this->penButton->Size = System::Drawing::Size(20, 20);
			this->penButton->Text = L"toolStripButton5";
			this->penButton->Click += gcnew System::EventHandler(this, &Interface::penButtonClick);
			// 
			// eraserButton
			// 
			this->eraserButton->AutoSize = false;
			this->eraserButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"eraserButton.BackgroundImage")));
			this->eraserButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->eraserButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->eraserButton->Name = L"eraserButton";
			this->eraserButton->Size = System::Drawing::Size(20, 20);
			this->eraserButton->Text = L"toolStripButton4";
			this->eraserButton->Click += gcnew System::EventHandler(this, &Interface::eraserButtonClick);
			// 
			// clearButton
			// 
			this->clearButton->AutoSize = false;
			this->clearButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearButton.BackgroundImage")));
			this->clearButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->clearButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(20, 20);
			this->clearButton->Text = L"toolStripButton6";
			this->clearButton->Click += gcnew System::EventHandler(this, &Interface::clearButton_Click);
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(561, 450);
			this->Controls->Add(this->toolStripTools);
			this->Controls->Add(this->toolStripColor);
			this->Controls->Add(this->canvas);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Interface";
			this->Text = L"BestGraphicEditorEver";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			this->toolStripColor->ResumeLayout(false);
			this->toolStripColor->PerformLayout();
			this->toolStripTools->ResumeLayout(false);
			this->toolStripTools->PerformLayout();
			this->ResumeLayout(false);

		}

		void paint() {

			Graphics^ a = canvas->CreateGraphics();

			switch (checkInstrument) {
			case(pen):
			{
				Pen^ pen = gcnew Pen(CurrentColor, width);
				a->DrawLine(pen, PreviousPoint, CurrentPoint);
				break;
			}
			case(eraser):
			{
				Pen^ pen = gcnew Pen(Color::White, width);
				a->DrawLine(pen, PreviousPoint, CurrentPoint);
				break;
			}
			case(rectangle):
			{
				Pen^ pen = gcnew Pen(CurrentColor, width);
				a->DrawRectangle(pen, Math::Min(PreviousPoint.X, CurrentPoint.X),
					Math::Min(PreviousPoint.Y, CurrentPoint.Y),
					Math::Abs(PreviousPoint.X - CurrentPoint.X),
					Math::Abs(PreviousPoint.Y - CurrentPoint.Y));
				break;
			}
			case(ellipse):
			{
				Pen^ pen = gcnew Pen(CurrentColor, width);
				a->DrawEllipse(pen, Math::Min(PreviousPoint.X, CurrentPoint.X),
					Math::Min(PreviousPoint.Y, CurrentPoint.Y),
					Math::Abs(PreviousPoint.X - CurrentPoint.X),
					Math::Abs(PreviousPoint.Y - CurrentPoint.Y));
				break;
			}
			case(stroke):
			{
				Pen^ pen = gcnew Pen(CurrentColor, width);
				a->DrawLine(pen, PreviousPoint, CurrentPoint);
				break;
			}
			}
		}

		private: System::Void canvas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			isPressed = false;
			if (checkInstrument == 3 || checkInstrument == 4 || checkInstrument == 5) {
				CurrentPoint = e->Location;
				paint();				
			}
		}

		private: System::Void canvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			isPressed = true;
			PreviousPoint = e->Location;
		}

		private: System::Void canvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (isPressed) {
				if (checkInstrument == 1 || checkInstrument == 2) {
					CurrentPoint = PreviousPoint;
					PreviousPoint = e -> Location;
					paint();					
				}
			}
		}		

		private: System::Void blackColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Black;
		}
		private: System::Void greyColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Gray;
		}
		private: System::Void whiteColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::White;
		}
		private: System::Void redColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Red;
		}
		private: System::Void yellowColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Yellow;
		}
		private: System::Void greenColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Green;
		}
		private: System::Void blueColorButtonClick(System::Object^  sender, System::EventArgs^  e) {
			CurrentColor = Color::Blue;
		}

		private: System::Void penButtonClick(System::Object^  sender, System::EventArgs^  e) {
			checkInstrument = 1;
		}
		private: System::Void eraserButtonClick(System::Object^  sender, System::EventArgs^  e) {
			checkInstrument = 2;
		}
		private: System::Void rectangleButtonClick(System::Object^  sender, System::EventArgs^  e) {
			checkInstrument = 3;
		}
		private: System::Void ellipseButtonClick(System::Object^  sender, System::EventArgs^  e) {
			checkInstrument = 4;
		}
		private: System::Void strokeButtonClick(System::Object^  sender, System::EventArgs^  e) {
			checkInstrument = 5;
		}		
		private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
			canvas->Refresh();
		}

		private: System::Void widthOnePixelClick(System::Object^  sender, System::EventArgs^  e) {
			width = 1;
		}
		private: System::Void widthThreePixelsClick(System::Object^  sender, System::EventArgs^  e) {
			width = 3;
		}
		private: System::Void widthFivePixelsClick(System::Object^  sender, System::EventArgs^  e) {
			width = 5;
		}
		private: System::Void widthEightPixelsClick(System::Object^  sender, System::EventArgs^  e) {
			width = 8;
		}
};
}
