#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class MyApp: public wxApp
{
	public:
		virtual bool OnInit();
};

class MyFrame: public wxFrame
{
	public:
		MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	private:
		void OnHello(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

		wxDECLARE_EVENT_TABLE();
};

enum {
	ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello, MyFrame::OnHello)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(800,600));
	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Hello string shown in status bar for this menu item");
	menuFile->AppendSeparator();

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_EXIT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);
	
	CreateStatusBar();
	SetStatusText("Welcom to wxWidgets!");
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidget' Hello World Sample", "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello World from wxWidgets!");
}
