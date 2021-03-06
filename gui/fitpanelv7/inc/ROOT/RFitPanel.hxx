// \file ROOT/RFitPanel.hxx
/// \ingroup WebGui ROOT7
/// \author Sergey Linev <S.Linev@gsi.de>
/// \author Iliana Betsou <Iliana.Betsou@cern.ch>
/// \date 2019-04-11
/// \warning This is part of the ROOT 7 prototype! It will change without notice. It might trigger earthquakes. Feedback
/// is welcome!

/*************************************************************************
 * Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_RFitPanel
#define ROOT_RFitPanel

#include <ROOT/RWebWindow.hxx>

#include <ROOT/RFitPanelModel.hxx>

#include <ROOT/RCanvas.hxx>

#include "ROOT/RHist.hxx"

#include <memory>
#include <vector>

class TPad;
class TH1;

namespace ROOT {
namespace Experimental {

class RFitPanel {

   std::unique_ptr<RFitPanelModel> fModel;

   TH1 *fHist{nullptr};              ///<! explicit histogram used for fitting
   std::string fCanvName{"c1"};      ///<! v6 canvas name used to display fit, will be created if not exists

   std::shared_ptr<RCanvas> fCanvas; ///!< v7 canvas used to display results
   std::shared_ptr<RH1D> fFitHist;   ///!< v7 histogram for fitting

   std::shared_ptr<RWebWindow> fWindow; ///!< configured display
   unsigned fConnId{0};              ///<! client connection id

   /// process data from UI
   void ProcessData(unsigned connid, const std::string &arg);

   int UpdateModel(const std::string &json);

   void DoFit(const std::string &model);

   void DrawContour(const std::string &model);

   void DrawScan(const std::string &model);

   RFitPanelModel &model();

   TPad *GetDrawPad(TH1 *hist);

   void SendModel();

public:
   /// normal constructor
   RFitPanel(const std::string &title = "Fit panel");

   // method required when any panel want to be inserted into the RCanvas
   std::shared_ptr<RWebWindow> GetWindow();

   void AssignHistogram(TH1 *hist);

   void AssignHistogram(const std::string &hname);

   void AssignCanvas(const std::string &cname) { fCanvName = cname; }

   void AssignCanvas(std::shared_ptr<RCanvas> &canv);

   void AssignHistogram(std::shared_ptr<RH1D> &hist);

   /// show FitPanel in specified place
   void Show(const std::string &where = "");

   /// hide FitPanel
   void Hide();
};

} // namespace Experimental
} // namespace ROOT

#endif
