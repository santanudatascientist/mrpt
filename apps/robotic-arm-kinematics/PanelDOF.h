/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2023, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */

#ifndef PANELDOF_H
#define PANELDOF_H

//(*Headers(PanelDOF)
#include <wx/htmllbox.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
//*)

class PanelDOF : public wxPanel
{
   public:
	PanelDOF(wxWindow* parent, wxWindowID id = wxID_ANY);
	~PanelDOF() override;

	//(*Declarations(PanelDOF)
	wxSimpleHtmlListBox* Label1;
	wxTextCtrl* TextCtrl1;
	wxSlider* Slider1;
	//*)

   protected:
	//(*Identifiers(PanelDOF)
	static const long ID_SIMPLEHTMLLISTBOX2;
	static const long ID_SLIDER1;
	static const long ID_TEXTCTRL1;
	//*)

   private:
	//(*Handlers(PanelDOF)
	void OnSlider1CmdScroll(wxScrollEvent& event);
	//*)

	DECLARE_EVENT_TABLE()
};

#endif
