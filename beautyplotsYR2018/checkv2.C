#include "TRandom.h"
#include "TFile.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TStyle.h"
#include "TFile.h"
#include "TList.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include "TTree.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TTree.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "Riostream.h"

void checkv2()
{
    Double_t yB = 0.036;
    Double_t erryieldB = 0.05;                                                                                                          // 3%
    Double_t formula = TMath::Pi() / 4. * (1 - (4 * yB / TMath::Pi()) * (4 * yB / TMath::Pi())) / TMath::Sqrt(1 - yB * yB) * erryieldB; //TDR
    Double_t formula2 = TMath::Pi() / 4. * TMath::Sqrt(2 + 2*4 * yB / TMath::Pi() * 4 * yB / TMath::Pi()) * erryieldB;                    //considering sigma_in=sigma_out=sigma_tot=erryieldB
    Double_t formula3 = yB * TMath::Pi() / 4. * TMath::Sqrt(2 * erryieldB * erryieldB * 2);                                             //considering sigma_(Nin-Nout)=sigma_(Nin+Nout)=erryieldB*sqrt(2)
    Double_t formula4 = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1.-4 * yB / TMath::Pi() * 4 * yB / TMath::Pi()  )*erryieldB;                                         


    printf("formula1=%f, formula2=%f, formula3=%f, formula4=%f \n", formula, formula2, formula3, formula4);
}