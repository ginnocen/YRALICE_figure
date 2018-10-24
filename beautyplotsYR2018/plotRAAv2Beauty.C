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
void plotRAAv2Beauty()
{
    gStyle->SetOptStat(0);

    ///////////////
    //non-prompt D0 RAA (BAMPS curve)
    ///////////////

    TFile *fDB = new TFile("D0RAAnonprompt_TDR.root");
    TCanvas *cc = (TCanvas *)fDB->Get("cRAAsec");

    TList *list = cc->GetListOfPrimitives();
    TH1F *hRaaSec = (TH1F *)list->FindObject("hRaaSec");
    Double_t x[11], y[11], ex[11], ey[11];
    x[0] = 0.5;
    y[0] = -1;
    ex[0] = 0.025;
    ey[0] = 0;
    x[1] = 1.5;
    y[1] = -1;
    ex[1] = 0.025;
    ey[1] = 0;
    x[2] = 2.5;
    y[2] = 1.2;
    ex[2] = 0.2;
    ey[2] = 0.238349;
    x[3] = 3.5;
    y[3] = 0.8;
    ex[3] = 0.2;
    ey[3] = 0.126115;
    x[4] = 4.5;
    y[4] = 0.5;
    ex[4] = 0.2;
    ey[4] = 0.0652485;
    x[5] = 5.5;
    y[5] = 0.4;
    ex[5] = 0.2;
    ey[5] = 0.0518228;
    x[6] = 7;
    y[6] = 0.33;
    ex[6] = 0.2;
    ey[6] = 0.0306553;
    x[7] = 10;
    y[7] = 0.3;
    ex[7] = 0.2;
    ey[7] = 0.0271044;
    x[8] = 14;
    y[8] = 0.3;
    ex[8] = 0.2;
    ey[8] = 0.0211341;
    x[9] = 20;
    y[9] = 0.32;
    ex[9] = 0.2;
    ey[9] = 0.0239993;
    x[10] = 28;
    y[10] = 0.38;
    ex[10] = 0.2;
    ey[10] = 0.0320427;

    TGraphErrors *grD0Raasyst = new TGraphErrors(11);
    grD0Raasyst->SetFillStyle(0);
    grD0Raasyst->SetLineColor(2);
    hRaaSec->SetMinimum(0);
    hRaaSec->SetMaximum(2);
    hRaaSec->SetTitle(0);
    hRaaSec->GetXaxis()->SetRangeUser(0, 35);
    hRaaSec->SetMarkerStyle(20);
    hRaaSec->SetMarkerSize(1.0);
    hRaaSec->SetMarkerColor(2);
    hRaaSec->GetYaxis()->SetTitle("#it{R}_{AA}");
    hRaaSec->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");

    //print on file
    FILE *fDBout = fopen("fALICE_BeautyRAAv2.txt", "w");
    //pt,RAA,ex,stat,syst
    fprintf(fDBout, "B->D0 (0-10%% centr., Lint=10nb-1): pt, width x, RAA (BAMPS), err stat, err syst \n \n \n");
    printf("B->D0 (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst \n \n \n");
    for (Int_t ii = 0; ii < 11; ii++)
    {
        fprintf(fDBout, "%f, %f, %f, %f, %f \n", x[ii], hRaaSec->GetBinWidth(ii + 1), y[ii], hRaaSec->GetBinError(ii + 1), ey[ii]);
        printf("%f, %f, %f, %f, %f \n", x[ii], hRaaSec->GetBinWidth(ii + 1), y[ii], hRaaSec->GetBinError(ii + 1), ey[ii]);
        grD0Raasyst->SetPoint(ii, x[ii], y[ii]);
        grD0Raasyst->SetPointError(ii, ex[ii], ey[ii]);
    }

    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    TLatex *texD00 = new TLatex(3., 1.8, "ALICE Upgrade Simulation");
    texD00->SetTextFont(42);
    texD00->SetLineWidth(2);

    TLatex *texD0 = new TLatex(3., 1.6, "0-10% Pb-Pb, #sqrt{s_{NN}}=5.5 TeV, #it{L}_{int} = 10 nb^{-1}");
    texD0->SetTextFont(42);
    texD0->SetTextSize(0.05);
    TLatex *texD02 = new TLatex(3.8, 1.6, "Non-prompt D^{0}#rightarrow K^{-} #pi^{+}");
    texD02->SetTextFont(42);
    texD02->SetTextSize(0.04);

    // texD02->Draw();

    ///////////////
    //non-prompt JPsi RAA (Fiorella, TAMU curve)
    ///////////////

    Double_t xJP[9], yJP[9], exJP[9], eyJP[9];
    xJP[0] = 1.42222;
    yJP[0] = 1.20907;
    exJP[0] = 0.5;
    eyJP[0] = 0.054108;
    xJP[1] = 2.49748;
    yJP[1] = 1.25246;
    exJP[1] = 0.5;
    eyJP[1] = 0.05709;
    xJP[2] = 3.5;
    yJP[2] = 1.2;
    exJP[2] = 0.5;
    eyJP[2] = 0.0491436;
    xJP[3] = 4.5;
    yJP[3] = 1.15;
    exJP[3] = 0.5;
    eyJP[3] = 0.0461817;
    xJP[4] = 5.5;
    yJP[4] = 1;
    exJP[4] = 0.5;
    eyJP[4] = 0.040113;
    xJP[5] = 6.5;
    yJP[5] = 0.85;
    exJP[5] = 0.5;
    eyJP[5] = 0.0405611;
    xJP[6] = 7.5;
    yJP[6] = 0.7;
    exJP[6] = 0.5;
    eyJP[6] = 0.0396018;
    xJP[7] = 8.5;
    yJP[7] = 0.6;
    exJP[7] = 0.5;
    eyJP[7] = 0.0415938;
    xJP[8] = 9.5;
    yJP[8] = 0.5;
    exJP[8] = 0.5;
    eyJP[8] = 0.0462625;
    TGraphErrors *grJP = new TGraphErrors(9);
    grJP->SetMarkerStyle(23);
    grJP->SetMarkerSize(1.2);
    grJP->SetMarkerColor(kMagenta + 1);
    grJP->SetLineColor(1);

    Double_t relSystUncRaa[] = {0.200475, 0.150343, 0.136065, 0.143309, 0.157946, 0.157053, 0.152453, 0.147001, 0.144566};
    Double_t absSystUncRaa[9];
    fprintf(fDBout, "B->JPsi->e+e- (mid) (0-10%% centr., Lint=10nb-1): pt, width x, RAA (TAMU), err stat, err syst \n \n \n");
    printf("B->JPsi->e+e- (mid) (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst \n \n \n");
    for (Int_t ii = 0; ii < 9; ii++)
    {
        absSystUncRaa[ii] = relSystUncRaa[ii] * yJP[ii];
        fprintf(fDBout, "%f, %f, %f, %f %f\n", xJP[ii], exJP[ii] * 2, yJP[ii], eyJP[ii], absSystUncRaa[ii]);
        printf("%f, %f, %f, %f %f \n", xJP[ii], exJP[ii] * 2, yJP[ii], eyJP[ii], absSystUncRaa[ii]);
        grJP->SetPoint(ii, xJP[ii], yJP[ii]);
        grJP->SetPointError(ii, exJP[ii], eyJP[ii]);
    }
    TGraphAsymmErrors *aliceSystJP = new TGraphAsymmErrors(9, xJP, yJP, exJP, exJP, absSystUncRaa, absSystUncRaa);
    //  aliceSystJP->SetMarkerStyle(23);
    //aliceSyst->SetMarkerSize(0.6);
    //aliceSyst->SetMarkerColor(1);
    aliceSystJP->SetLineColor(kMagenta + 1);
    // aliceSyst->SetLineWidth(1.5);
    aliceSystJP->SetFillStyle(0);

    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");
    TLatex *texJP = new TLatex(15, 1.4, "Non-prompt J/#psi #rightarrow e^{+}e^{-}");
    texJP->SetTextFont(42);
    texJP->SetTextSize(0.04);
    texJP->SetTextColor(2);

    /////////////
    ///// B->J/Psi   ////////
    //da A. Uras non-prompt Jpsi->mumu forward with MFT (BAMPS curve)
    // p_T    R_AA
    // 0-1    1.65 ± 1.5% (stat.) ± 6% (syst.)
    // 1-2    1.45 ± 0.9% (stat.) ± 5% (syst.)
    // 2-3    1.20+/- 0.8% (stat.) ± 5% (syst.)
    fprintf(fDBout, "B->JPsi->mu+mu- (fwd) (0-10%% centr., Lint=10nb-1): pt, width x, RAA (BAMPS), err stat, err syst \n \n \n");
    printf("B->JPsi->mu+mu- (fwd) (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst \n \n \n");

    TH1F *hRAAnpJPfw = new TH1F("hRAAnpJPfw", "", 3, 0, 3);
    hRAAnpJPfw->SetBinContent(1, 1.65);
    hRAAnpJPfw->SetBinContent(2, 1.45);
    hRAAnpJPfw->SetBinContent(3, 1.2);
    hRAAnpJPfw->SetBinError(1, 1.65 * 0.015);
    hRAAnpJPfw->SetBinError(2, 1.45 * 0.009);
    hRAAnpJPfw->SetBinError(3, 1.2 * 0.008);
    hRAAnpJPfw->SetMarkerStyle(22);
    hRAAnpJPfw->SetMarkerSize(1.2);
    hRAAnpJPfw->SetMarkerColor(kGreen + 2);
    hRAAnpJPfw->SetLineColor(1);
    hRAAnpJPfw->SetLineWidth(2);

    TGraphErrors *grnpJPfw = new TGraphErrors(3);
    grnpJPfw->SetPoint(0, 0.5, 1.65);
    grnpJPfw->SetPoint(1, 1.5, 1.45);
    grnpJPfw->SetPoint(2, 2.5, 1.2);
    grnpJPfw->SetPointError(0, 0.1, 1.65 * 0.06);
    grnpJPfw->SetPointError(1, 0.1, 1.45 * 0.05);
    grnpJPfw->SetPointError(2, 0.1, 1.2 * 0.05);
    grnpJPfw->SetLineColor(kGreen + 2);
    grnpJPfw->SetFillStyle(0);
    for (Int_t ii = 0; ii < 3; ii++)
    {
        fprintf(fDBout, "%f, %f, %f, %f %f\n", hRAAnpJPfw->GetBinCenter(ii + 1), hRAAnpJPfw->GetBinWidth(ii + 1), hRAAnpJPfw->GetBinContent(ii + 1), hRAAnpJPfw->GetBinError(ii + 1), absSystUncRaa[ii]);
        printf("%f, %f, %f, %f %f \n", xJP[ii], exJP[ii] * 2, yJP[ii], eyJP[ii], absSystUncRaa[ii]);
    }
    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    ///////////////
    //B+->D0pi+ RAA (TAMU curve)
    ///////////////

    const Int_t nptbins = 11;
    Double_t ptbins[nptbins + 1] = {1., 2., 3., 4., 5., 6, 8, 12, 16, 20, 24};
    Double_t ptbinCenters[nptbins] = {1.5, 2.5, 3.5, 4.5, 5.5, 7., 10., 14., 18., 22., 32.};
    Double_t ptbinHalfwidths[nptbins] = {.5, .5, .5, .5, .5, 1., 2., 2., 2., 2., 8.};
    Double_t xwidthsForSyst[nptbins] = {0.25};

    // RAA values in 0-10%  from Johannes' figures
    Double_t RAAvalue[nptbins] = {1.06, 1.1, 1.047, 0.92, 0.78, 0.62, 0.488, 0.44, 0.456, 0.48, 0.495};
    Double_t errRAAvalue[nptbins] = {0.2, 0.1, 0.071, 0.05, 0.04, 0.03, 0.012, 0.02, 0.02, 0.03, 0.025};
    Double_t v2value[nptbins] = {0.0146, 0.0326, 0.054, 0.067, 0.068, 0.064, 0.047, 0.031, 0.022, 0., 0.};
    Double_t errv2value[nptbins] = {0.0324, 0.0234, 0.022, 0.02, 0.025, 0.021, 0.016, 0.019, 0.027, 0.038, 0.031};

    const Int_t nsourceSystUnCorr = 5;
    const Int_t nsourceSystCorr = 1;

    // NOW SET THE SYST UNCERTAINTY: FOR THE MOMENT pt-INDEPENDENT (same as those )
    Double_t uncorrSystUncBPbPb[nsourceSystUnCorr] = {
        0.07, //tracking efficiency
        0.07, // PID
        0.05, // yield extr
        0.05, // MC corr
        0.03  // MC pt shape
        //0.12  // No fd uncert
    };
    Double_t corrSystUncBPbPb[nsourceSystCorr] = {
        // 0.1, // Feed-down ("FONLL") // No fd uncert
        0.03 // branching ratio
    };

    Double_t uncorrSystUncBpp[nsourceSystUnCorr] = {
        0.07, //tracking efficiency
        0.07, // PID
        0.05, // yield extr
        0.05, // MC corr
        0.03  // MC pt shape
              //  0.    /
    };
    Double_t corrSystUncBpp[nsourceSystCorr] = {
        //  0.1, // Feed-down ("FONLL")
        0.03 // branching ratio
    };
    Double_t totalSystBRAA = 0.;
    for (Int_t source = 0; source < nsourceSystUnCorr; source++)
    { // SUM IN QUADRATURE UNCORR SOURCES
        totalSystBRAA += uncorrSystUncBPbPb[source] * uncorrSystUncBPbPb[source] + uncorrSystUncBpp[source] * uncorrSystUncBpp[source];
    }

    for (Int_t source = 0; source < nsourceSystCorr; source++)
    { // TREAT PROPERLY CORR SOURCES
        totalSystBRAA += corrSystUncBPbPb[source] * corrSystUncBPbPb[source] - corrSystUncBpp[source] * corrSystUncBpp[source];
    }
    totalSystBRAA = TMath::Sqrt(totalSystBRAA);

    TGraphErrors *grB = new TGraphErrors(nptbins);
    grB->SetMarkerStyle(34);
    grB->SetMarkerSize(1.3);
    grB->SetMarkerColor(4);
    grB->SetLineColor(1);
    grB->SetLineWidth(2);

    TGraphErrors *grBsyst = new TGraphErrors(nptbins);
    grBsyst->SetMarkerColor(4);
    grBsyst->SetLineColor(4);
    grBsyst->SetFillStyle(0);
    fprintf(fDBout, "B->D0pi (0-10%% centr., Lint=10nb-1): pt, width x, RAA (TAMU), err stat, err syst \n \n \n");
    printf("B->D0pi (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst \n \n \n");

    for (Int_t ii = 0; ii < nptbins; ii++)
    {
        fprintf(fDBout, "%f, %f, %f, %f, %f \n", ptbinCenters[ii], ptbinHalfwidths[ii] * 2, RAAvalue[ii], errRAAvalue[ii], RAAvalue[ii] * totalSystBRAA);
        printf("%f, %f, %f, %f, %f \n", ptbinCenters[ii], ptbinHalfwidths[ii] * 2, RAAvalue[ii], errRAAvalue[ii], RAAvalue[ii] * totalSystBRAA);
        grB->SetPoint(ii, ptbinCenters[ii], RAAvalue[ii]);
        grB->SetPointError(ii, ptbinHalfwidths[ii], errRAAvalue[ii]);
        grBsyst->SetPoint(ii, ptbinCenters[ii], RAAvalue[ii]);
        grBsyst->SetPointError(ii, 0.2, RAAvalue[ii] * totalSystBRAA);
    }
    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    TLatex *texB = new TLatex(15, 1.2, "B^{+} #rightarrow D^{0}#pi^{+}");
    texB->SetTextFont(42);
    texB->SetTextSize(0.04);
    texB->SetTextColor(4);

    //  texB->Draw();

    TLegend *legraa = new TLegend(0.35, 0.4, 0.8, 0.7);
    legraa->AddEntry(hRaaSec, "D^{0} from B", "p");
    legraa->AddEntry(grB, "B^{+}#rightarrow D^{0}#pi^{+}", "p");
    legraa->AddEntry(grJP, "J/#psi(#rightarrow e^{+}e^{-}) from B (mid-rapidity)", "p");
    legraa->AddEntry(hRAAnpJPfw, "J/#psi(#rightarrow #mu^{+}#mu^{-}) from B (2.5<y<3.6)", "p");
    legraa->SetTextFont(42);
    legraa->SetLineWidth(2);
    legraa->SetBorderSize(0);

    TCanvas *can = new TCanvas("can", "can", 800, 650);
    can->SetLeftMargin(0.13);
    can->SetBottomMargin(0.13);
    can->SetTickx();
    can->SetTicky();

    hRaaSec->Draw();
    grD0Raasyst->Draw("2same");
    texD00->Draw();
    texD0->Draw();
    grJP->Draw("pzsame");
    aliceSystJP->Draw("E2 SAME");

    //texJP->Draw();
    grB->Draw("pzsame");
    grBsyst->Draw("2same");
    hRAAnpJPfw->Draw("same");
    grnpJPfw->Draw("2same");
    legraa->Draw();
    can->SaveAs("ALICEUpgrade_beautyRAA.eps");
    can->SaveAs("ALICEUpgrade_beautyRAA.pdf");

    ///figure for YR, also with D0////
    ///////////////
    //prompt D0 RAA
    ///////////////

    TFile *fD = new TFile("../charmplotsYR2018/D0RAAprompt_TDR.root");
    cc = (TCanvas *)fD->Get("cRAAprompt");

    list = cc->GetListOfPrimitives();
    TH1F *hRaaPrompt = (TH1F *)list->FindObject("hRaaPrompt");
    // Double_t x[11], y[11], exl[11], eyl[11], exh[11], eyh[11];
    Double_t exl[11], eyl[11], exh[11], eyh[11];
    x[0] = 0.5;
    y[0] = 0.8;
    exl[0] = 0.2;
    exh[0] = 0.2;
    eyl[0] = 0.101075;
    eyh[0] = 0.0761589;
    x[1] = 1.5;
    y[1] = 0.65;
    exl[1] = 0.2;
    exh[1] = 0.2;
    eyl[1] = 0.0710934;
    eyh[1] = 0.0462496;
    x[2] = 2.5;
    y[2] = 0.51495;
    exl[2] = 0.2;
    exh[2] = 0.2;
    eyl[2] = 0.033148;
    eyh[2] = 0.033148;
    x[3] = 3.5;
    y[3] = 0.371069;
    exl[3] = 0.2;
    exh[3] = 0.2;
    eyl[3] = 0.0227283;
    eyh[3] = 0.0227283;
    x[4] = 4.5;
    y[4] = 0.330109;
    exl[4] = 0.2;
    exh[4] = 0.2;
    eyl[4] = 0.0195342;
    eyh[4] = 0.0195342;
    x[5] = 5.5;
    y[5] = 0.271764;
    exl[5] = 0.2;
    exh[5] = 0.2;
    eyl[5] = 0.0160816;
    eyh[5] = 0.0160816;
    x[6] = 7;
    y[6] = 0.283102;
    exl[6] = 0.2;
    exh[6] = 0.2;
    eyl[6] = 0.0158792;
    eyh[6] = 0.0158792;
    x[7] = 10;
    y[7] = 0.256087;
    exl[7] = 0.2;
    exh[7] = 0.2;
    eyl[7] = 0.014364;
    eyh[7] = 0.014364;
    x[8] = 14;
    y[8] = 0.349423;
    exl[8] = 0.2;
    exh[8] = 0.2;
    eyl[8] = 0.0195992;
    eyh[8] = 0.0195992;
    x[9] = 20;
    y[9] = 0.37;
    exl[9] = 0.2;
    exh[9] = 0.2;
    eyl[9] = 0.0228323;
    eyh[9] = 0.0228323;
    x[10] = 28;
    y[10] = 0.4;
    exl[10] = 0.2;
    exh[10] = 0.2;
    eyl[10] = 0.0291031;
    eyh[10] = 0.0291031;
    //print on file

    TGraphAsymmErrors *grD0PRaasyst = new TGraphAsymmErrors(11);
    grD0PRaasyst->SetFillStyle(0);
    grD0PRaasyst->SetLineColor(1);
    hRaaPrompt->SetMinimum(0);
    hRaaPrompt->SetMaximum(2);
    hRaaPrompt->SetTitle(0);
    hRaaPrompt->SetMarkerStyle(21);
    hRaaPrompt->SetMarkerSize(0.7);

    for (Int_t ii = 0; ii < 11; ii++)
    {
        grD0PRaasyst->SetPoint(ii, x[ii], y[ii]);
        grD0PRaasyst->SetPointError(ii, exl[ii], exh[ii], eyl[ii], eyh[ii]);
    }

    TLegend *legraa2 = new TLegend(0.35, 0.4, 0.8, 0.7);
    legraa2->AddEntry(hRaaPrompt, "Prompt D^{0}#rightarrow K^{-}#pi^{+}", "p");
    legraa2->AddEntry(hRaaSec, "D^{0} from B", "p");
    legraa2->AddEntry(grB, "B^{+}#rightarrow D^{0}#pi^{+}", "p");
    legraa2->AddEntry(grJP, "J/#psi(#rightarrow e^{+}e^{-}) from B (mid rapidity)", "p");
    legraa2->AddEntry(hRAAnpJPfw, "J/#psi(#rightarrow #mu^{+}#mu^{-}) from B (2.5<y<3.6)", "p");
    legraa2->SetTextFont(42);
    legraa2->SetLineWidth(2);
    legraa2->SetBorderSize(0);

    TCanvas *cancb = new TCanvas("cancb", "cancb", 800, 650);
    cancb->SetLeftMargin(0.13);
    cancb->SetBottomMargin(0.13);
    cancb->SetTickx();
    cancb->SetTicky();

    hRaaSec->Draw();
    grD0Raasyst->Draw("2same");
    hRaaPrompt->Draw("same");
    grD0PRaasyst->Draw("2same");
    texD00->Draw();
    texD0->Draw();
    grJP->Draw("pzsame");
    aliceSystJP->Draw("E2 SAME");

    //texJP->Draw();
    grB->Draw("pzsame");
    grBsyst->Draw("2same");
    hRAAnpJPfw->Draw("same");
    grnpJPfw->Draw("2same");
    legraa2->Draw();
    cancb->SaveAs("ALICEUpgrade_charmbeautyRAA.eps");
    cancb->SaveAs("ALICEUpgrade_charmbeautyRAA.pdf");

    /////////////////////////////////
    /////////////////////////////////
    /////////////////////////////////
    //// v2 ///////////
    /////////////////////////////////

    ///////////////
    //non-prompt D0 v2 (BAMPS curve)
    ///////////////

    Double_t xB[32],
        yB[32], exB[32], eyB[32], exsystB[32];
    xB[0] = 0.25;
    yB[0] = -0.5;
    exB[0] = 0;
    eyB[0] = 0.00892253;
    xB[1] = 0.75;
    yB[1] = -0.5;
    exB[1] = 0;
    eyB[1] = 0.00396557;
    xB[2] = 0.884734;
    yB[2] = 0.480554;
    exB[2] = 0;
    eyB[2] = 0.0523584;
    xB[3] = 1.59823;
    yB[3] = 0.488211;
    exB[3] = 0;
    eyB[3] = 0.0458047;
    xB[4] = 2.25;
    yB[4] = 0.024;
    exB[4] = 0;
    eyB[4] = 0.00396271;
    xB[5] = 2.75;
    yB[5] = 0.034;
    exB[5] = 0;
    eyB[5] = 0.00298631;
    xB[6] = 3.25;
    yB[6] = 0.054;
    exB[6] = 0;
    eyB[6] = 0.00306777;
    xB[7] = 3.75;
    yB[7] = 0.066;
    exB[7] = 0;
    eyB[7] = 0.00273462;
    xB[8] = 4.25;
    yB[8] = 0.07;
    exB[8] = 0;
    eyB[8] = 0.00112783;
    xB[9] = 4.75;
    yB[9] = 0.0725;
    exB[9] = 0;
    eyB[9] = 0.00115261;
    xB[10] = 5.25;
    yB[10] = 0.073;
    exB[10] = 0;
    eyB[10] = 0.00122898;
    xB[11] = 5.75;
    yB[11] = 0.074;
    exB[11] = 0;
    eyB[11] = 0.00122871;
    xB[12] = 6.25;
    yB[12] = 0.0715;
    exB[12] = 0;
    eyB[12] = 0.00113129;
    xB[13] = 6.75;
    yB[13] = 0.069;
    exB[13] = 0;
    eyB[13] = 0.00125972;
    xB[14] = 7.25;
    yB[14] = 0.067;
    exB[14] = 0;
    eyB[14] = 0.00139073;
    xB[15] = 7.75;
    yB[15] = 0.065;
    exB[15] = 0;
    eyB[15] = 0.00146633;
    xB[16] = 8.25;
    yB[16] = 0.063;
    exB[16] = 0;
    eyB[16] = 0.00124201;
    xB[17] = 8.75;
    yB[17] = 0.061;
    exB[17] = 0;
    eyB[17] = 0.00131859;
    xB[18] = 9.25;
    yB[18] = 0.059;
    exB[18] = 0;
    eyB[18] = 0.0014239;
    xB[19] = 9.75;
    yB[19] = 0.057;
    exB[19] = 0;
    eyB[19] = 0.00150659;
    xB[20] = 10.25;
    yB[20] = 0.055;
    exB[20] = 0;
    eyB[20] = 0.00159311;
    xB[21] = 10.75;
    yB[21] = 0.053;
    exB[21] = 0;
    eyB[21] = 0.00168426;
    xB[22] = 11.25;
    yB[22] = 0.051;
    exB[22] = 0;
    eyB[22] = 0.00178116;
    xB[23] = 11.75;
    yB[23] = 0.049;
    exB[23] = 0;
    eyB[23] = 0.00186687;
    xB[24] = 12.25;
    yB[24] = 0.047;
    exB[24] = 0;
    eyB[24] = 0.00406459;
    xB[25] = 12.75;
    yB[25] = 0.045;
    exB[25] = 0;
    eyB[25] = 0.00471028;
    xB[26] = 13.2425;
    yB[26] = 0.0431301;
    exB[26] = 0;
    eyB[26] = 0.00536006;
    xB[27] = 13.75;
    yB[27] = 0.041;
    exB[27] = 0;
    eyB[27] = 0.00601308;
    xB[28] = 14.25;
    yB[28] = 0.039;
    exB[28] = 0;
    eyB[28] = 0.00666889;
    xB[29] = 14.75;
    yB[29] = 0.038;
    exB[29] = 0;
    eyB[29] = 0.00732645;
    xB[30] = 15.25;
    yB[30] = 0.037;
    exB[30] = 0;
    eyB[30] = 0.00798662;
    xB[31] = 15.75;
    yB[31] = 0.036;
    exB[31] = 0;
    eyB[31] = 0.00863897;
    Double_t erryieldB;
    //Double_t erryieldB = 0.004; //Run2 is ~0.006-0.03 in 30-50%
    // Double_t erryield = 0.01;
    // Double_t errfdB = 0; //NO FD error

    Double_t fderryield[5] = {0.13, 0.1, 0.08, 0.05, 0.03}; //relative values in 2-3, 3-4,4-6,6-12, 12-16 (there are from unc on f_fd on yield extraction, not supposed to cancel in v2 formula)
    //Double_t fderryield[5] = {0.05, 0.05, 0.05, 0.05, 0.05}; //relative values in 2-3, 3-4,4-6,6-12, 12-16 (there are from unc on f_fd on yield extraction, not supposed to cancel in v2 formula)

    Double_t uncv2B[32];
    TGraphErrors *grD0FrBv2syst = new TGraphErrors(32);

    fprintf(fDBout, "B->D0 (30-50%% centr., Lint=10nb-1): pt, width x, v2 (BAMPS), err stat, err syst \n \n \n");
    printf("B->D0 (30-50%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");

    for (Int_t ii = 0; ii < 32; ii++)
    {
        exB[ii] = 0.25;
        exsystB[ii] = 0.1;

        if (xB[ii] >= 2 && xB[ii] < 3)
            erryieldB = fderryield[0];
        else if (xB[ii] >= 3 && xB[ii] < 4)
            erryieldB = fderryield[1];
        else if (xB[ii] >= 4 && xB[ii] < 6)
            erryieldB = fderryield[2];
        else if (xB[ii] >= 6 && xB[ii] < 12)
            erryieldB = fderryield[3];
        else if (xB[ii] >= 12)
            erryieldB = fderryield[4];

        // uncv2B[ii] = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1. - 4 * yB[ii] / TMath::Pi() * 4 * yB[ii] / TMath::Pi()) * erryieldB;
        Double_t uncv2Bformula = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1. - 4 * yB[ii] / TMath::Pi() * 4 * yB[ii] / TMath::Pi()) * erryieldB;

        if (xB[ii] >= 2 && xB[ii] < 3)
            erryieldB = 0.025;
        else if (xB[ii] >= 3 && xB[ii] < 4)
            erryieldB = 0.025;
        else if (xB[ii] >= 4 && xB[ii] < 6)
            erryieldB = 0.02;
        else if (xB[ii] >= 6 && xB[ii] < 12)
            erryieldB = 0.02;
        else if (xB[ii] >= 12)
            erryieldB = 0.015;

        uncv2B[ii] = erryieldB;

        grD0FrBv2syst->SetPoint(ii, xB[ii], yB[ii]);
        grD0FrBv2syst->SetPointError(ii, exsystB[ii], uncv2B[ii]);

        cout << xB[ii] << "  v2=" << yB[ii] << " uncv2= " << uncv2B[ii] << " uncv2Formula= " << uncv2Bformula << endl;
    }

    for (Int_t ii = 0; ii < 32; ii++)
    {
        fprintf(fDBout, "%f, %f, %f, %f, %f \n", xB[ii], exB[ii], yB[ii], eyB[ii], uncv2B[ii]);
        printf("%f, %f, %f, %f, %f \n", xB[ii], exB[ii], yB[ii], eyB[ii], uncv2B[ii]);
    }
    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    grD0FrBv2syst->SetFillStyle(0);
    grD0FrBv2syst->SetLineColor(1);
    //grD0FrBv2syst->SetLineColor(2);
    TGraphErrors *grD0FrBv2 = new TGraphErrors(32, xB, yB, exB, eyB);
    grD0FrBv2->SetMarkerStyle(20);
    grD0FrBv2->SetMarkerColor(1);
    // grD0FrBv2->SetMarkerColor(2);
    grD0FrBv2->SetMarkerSize(1.);
    grD0FrBv2->SetLineWidth(2);
    grD0FrBv2->GetYaxis()->SetRangeUser(-0.05, 0.3);
    grD0FrBv2->GetXaxis()->SetRangeUser(0, 16);
    grD0FrBv2->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
    grD0FrBv2->GetYaxis()->SetTitle("#it{v}_{2}");
    grD0FrBv2->SetTitle("");
    grD0FrBv2->GetYaxis()->SetTitleSize(0.05);
    grD0FrBv2->GetXaxis()->SetTitleSize(0.05);
    grD0FrBv2->GetXaxis()->SetLabelSize(0.05);
    grD0FrBv2->GetYaxis()->SetLabelSize(0.05);
    grD0FrBv2->GetYaxis()->SetTitleOffset(1.2);

    ///////////////
    //non-prompt JPSi v2 (Fiorella, TAMU)
    ///////////////

    Double_t xJPB[8], yJPB[8], exJPB[8], eyJPB[8], exsystJPB[8];
    xJPB[0] = 1.5;
    yJPB[0] = 0.013688;
    exJPB[0] = 0.2;
    eyJPB[0] = 0.029737;
    xJPB[1] = 2.4838;
    yJPB[1] = 0.0411919;
    exJPB[1] = 0.2;
    eyJPB[1] = 0.029526;
    xJPB[2] = 3.4686;
    yJPB[2] = 0.0645492;
    exJPB[2] = 0.2;
    eyJPB[2] = 0.01859;
    xJPB[3] = 4.5;
    yJPB[3] = 0.069582;
    exJPB[3] = 0.2;
    eyJPB[3] = 0.02004;
    xJPB[4] = 5.5;
    yJPB[4] = 0.070152;
    exJPB[4] = 0.2;
    eyJPB[4] = 0.023406;
    xJPB[5] = 6.5;
    yJPB[5] = 0.064449;
    exJPB[5] = 0.2;
    eyJPB[5] = 0.031562;
    xJPB[6] = 7.5;
    yJPB[6] = 0.061597;
    exJPB[6] = 0.2;
    eyJPB[6] = 0.039767;
    xJPB[7] = 8.99004;
    yJPB[7] = 0.0562162;
    exJPB[7] = 0.2;
    eyJPB[7] = 0.042339;

    fprintf(fDBout, "B->J/Psi->e+e- (10-40%% centr., Lint=10nb-1): pt, width x, v2 (TAMU), err stat, err syst \n \n \n");
    printf("B->J/Psi (10-40%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");

    for (Int_t ii = 0; ii < 8; ii++)
    {
        fprintf(fDBout, "%f, %f, %f, %f \n", xJPB[ii], exJPB[ii] * 2, yJPB[ii], eyJPB[ii]);
        printf("%f, %f, %f, %f \n", xJPB[ii], exJPB[ii] * 2, yJPB[ii], eyJPB[ii]);
    }
    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    TGraphErrors *grJPBv2 = new TGraphErrors(8, xJPB, yJPB, exJPB, eyJPB);
    // grJPBv2->SetMarkerStyle(21);
    // grJPBv2->SetMarkerColor(2);
    // grJPBv2->SetMarkerSize(1.);
    // grJPBv2->SetLineWidth(2);
    //  grJPBv2->SetLineColor(2);

    grJPBv2->SetMarkerStyle(23);
    grJPBv2->SetMarkerSize(1.4);
    grJPBv2->SetMarkerColor(kMagenta + 1);
    grJPBv2->SetLineColor(kMagenta + 1);
    grJPBv2->SetLineWidth(2);
    ///////////////
    //B+ v2 (TAMU curve)
    ///////////////

    TGraphErrors *grBv2 = new TGraphErrors(nptbins);
    // grBv2->SetMarkerStyle(20);
    // grBv2->SetMarkerColor(4);
    // grBv2->SetLineColor(1);
    grBv2->SetMarkerStyle(34);
    grBv2->SetMarkerSize(1.4);
    grBv2->SetMarkerColor(4);
    grBv2->SetLineColor(1);
    grBv2->SetLineWidth(2);

    Double_t erryieldBv2 = 0.05; //relative from TDR, as for Lc
    //  Double_t erryieldBv2 = 0.01;
    TGraphErrors *grBv2syst = new TGraphErrors(nptbins);
    grBv2syst->SetFillStyle(0);
    grBv2syst->SetLineColor(4);

    fprintf(fDBout, "B->D0pi (20-40%% centr., Lint=10nb-1): pt, width x, v2 (TAMU), err stat, err syst \n \n \n");
    printf("B->D0pi (20-40%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");
    Double_t uncv2Bplus[nptbins];

    for (Int_t ii = 0; ii < nptbins; ii++)
    {

        Double_t uncv2BplusFormula = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1. - 4 * v2value[ii] / TMath::Pi() * 4 * v2value[ii] / TMath::Pi()) * erryieldBv2;
        uncv2Bplus[ii] = 0.02;
        cout << ptbinCenters[ii] << "  v2=" << v2value[ii] << " uncv2= " << uncv2Bplus[ii] << " uncv2Formula= " << uncv2BplusFormula << endl;

        fprintf(fDBout, "%f, %f, %f, %f, %f \n", ptbinCenters[ii], ptbinHalfwidths[ii] * 2, v2value[ii], errv2value[ii], uncv2Bplus[ii]);
        printf("%f, %f, %f, %f, %f \n", ptbinCenters[ii], ptbinHalfwidths[ii] * 2, v2value[ii], errv2value[ii], uncv2Bplus[ii]);
        grBv2->SetPoint(ii, ptbinCenters[ii], v2value[ii]);
        grBv2->SetPointError(ii, ptbinHalfwidths[ii], errv2value[ii]);
        grBv2syst->SetPoint(ii, ptbinCenters[ii], v2value[ii]);
        grBv2syst->SetPointError(ii, 0.1, uncv2Bplus[ii]);
    }
    

    Double_t systUncTot[8]={0.036980,0.027655,0.032147,0.031989,0.019176,0.018925,0.017825,0.016130};
    // uncertainties non prompt jpsi (Fiorella)
    
    /*// correlation syst. unc. Nin / Nout yields
    Double_t rho = 0.85;

    /// sys Resolution
    Double_t systRes[10]={0.037652,0.029658,0.028581,0.023712,0.023213,0.014858,0.016027,0.012095,0.009997};

    /// sys bkg
    Double_t systBkg[10]={0.075228,0.056557,0.044106,0.045022,0.055216,0.056007,0.046980,0.032348,0.025471};

    // syst Incl. Jpsi
    Double_t inclJpsi[10]={0.15, 0.112,0.112,0.141,0.141,0.067,0.067,0.067,0.067,0.067};

    Double_t totUncYield[10];
    Double_t systUncTot[10];
    
    
   Double_t a = -1.;
   for(int ii=0; ii<8; ii++){
 	totUncYield[ii] = TMath::Sqrt(systRes[ii]*systRes[ii] + systBkg[ii]*systBkg[ii] + inclJpsi[ii]*inclJpsi[ii]);
        a = yJPB[ii]*4./TMath::Pi();  
	systUncTot[ii] = (TMath::Sqrt(2.*(1.-rho))/2.)*((1.-a*a)/a)*totUncYield[ii];
	}
  */
   TGraphErrors *grJPBv2syst = new TGraphErrors(8);

   for(int ip=0; ip<8; ip++){
     grJPBv2syst->SetPoint(ip, xJPB[ip], yJPB[ip]);
     // grJPBv2syst->SetPointError(ip,exJPB[ip],systUncTot[ip]*yJPB[ip]);
     grJPBv2syst->SetPointError(ip,exJPB[ip],systUncTot[ip]);
     }
    grJPBv2syst->SetMarkerStyle(21);
    grJPBv2syst->SetMarkerColor(kMagenta + 1);
    grJPBv2syst->SetMarkerSize(1.);
    grJPBv2syst->SetLineWidth(1);
    grJPBv2syst->SetLineColor(kMagenta + 1);
    grJPBv2syst->SetFillStyle(0);
    

    fprintf(fDBout, "\n \n \n");
    fprintf(fDBout, "================");
    fprintf(fDBout, "\n \n \n");
    printf("\n \n \n");
    printf("================");
    printf("\n \n \n");

    TLatex *tex0 = new TLatex(2, 0.27, "ALICE Upgrade Simulation");
    tex0->SetTextFont(42);
    tex0->SetLineWidth(2);
    TLatex *tex2 = new TLatex(2, 0.23, "Pb-Pb, #sqrt{s_{NN}}=5.5 TeV, #it{L}_{int} = 10 nb^{-1}");
    tex2->SetTextFont(42);
    tex2->SetLineWidth(2);

    TLegend *leg2 = new TLegend(0.15, 0.5, 0.8, 0.7);
    leg2->AddEntry(grD0FrBv2, "D^{0} from B, 30-50% centr.", "p");
    leg2->AddEntry(grJPBv2, "J/#psi(#rightarrow e^{+}e^{-}) from B, 10-40% centr.", "p");
    leg2->AddEntry(grBv2, "B^{+}#rightarrow D^{0}#pi^{+}, 20-40% centr.", "p");
    leg2->SetTextFont(42);
    leg2->SetLineWidth(2);
    leg2->SetBorderSize(0);
    TCanvas *can2 = new TCanvas("can2", "can2", 800, 650);
    can2->SetLeftMargin(0.13);
    can2->SetBottomMargin(0.13);
    can2->SetTickx();
    can2->SetTicky();


    grD0FrBv2->Draw("Apz");
    grBv2syst->Draw("2same");
    grJPBv2syst->Draw("2same");
    grD0FrBv2->Draw("pzsame");
    grD0FrBv2syst->Draw("2same");
    grJPBv2->Draw("pzsame");
    grBv2->Draw("pzsame");

    tex0->Draw();
    tex2->Draw();
    leg2->Draw();
    can2->SaveAs("ALICEUpgrade_beautyv2.pdf");
    ///////////////
    //Lb/B
    ///////////////

    ///

    Bool_t drawModels = kFALSE;
    //Double_t nev = 1.6e+10;
    const Int_t nptbinsLb = 4;
    Double_t ptbinsLb[nptbinsLb + 1] = {4., 7., 10., 14., 25.};
    Double_t ptbinCentersLb[nptbinsLb] = {5.5, 8.5, 12, 19.5};
    Double_t ptbinHalfwidthsLb[nptbinsLb] = {1.5, 1.5, 2., 5.5};
    Double_t xwidthsForSystLb[nptbinsLb] = {0.5, 0.5, 0.5, 0.5};

    Double_t errLb[nptbinsLb] = {0.28, 0.15, 0.11, 0.12};    //rel. stat. unc. Lb
    Double_t errB[nptbinsLb] = {0.025, 0.023, 0.054, 0.022}; //rel stat. unc B
    Double_t errT[nptbinsLb];                                //rel. stat. tot Lb + B

    for (Int_t i = 0; i < 4; i++)
    {
        errT[i] = TMath::Sqrt(errB[i] * errB[i] + errLb[i] * errLb[i]);
    }
    Double_t LbOverBpPbPb[nptbinsLb] = {5.84, 4.97, 3.76, 2.04}; //central values
    Double_t uncLbOvBpPbPb[6] = {
        0.02, //tracking efficiency
        0.05, // PID
        0.06, // yield extr
        0.07, // MC corr
        0.03, // MC pt shape
        0.10  // branching ratio
    };

    Double_t totuncLbOvBpPbPb = 0;
    for (Int_t ii = 0; ii < 6; ii++)
    {
        totuncLbOvBpPbPb += uncLbOvBpPbPb[ii] * uncLbOvBpPbPb[ii];
    }

    totuncLbOvBpPbPb = TMath::Sqrt(totuncLbOvBpPbPb);

    Printf("Unc Lb/Bp -> %f \n", totuncLbOvBpPbPb);
    Printf("Lb (0-20%% centr., Lint=10nb-1): pt, width x, Lb/Bp, err stat, err syst \n \n \n");

    Double_t uncStatLb[nptbinsLb];
    Double_t uncSystLbOvBpPbPb[nptbinsLb];
    for (Int_t npt = 0; npt < nptbinsLb; npt++)
    {
        uncSystLbOvBpPbPb[npt] = totuncLbOvBpPbPb * LbOverBpPbPb[npt];
        uncStatLb[npt] = errT[npt] * LbOverBpPbPb[npt];
        Printf("%f, %f, %f, %f, %f \n", ptbinCentersLb[npt], ptbinHalfwidthsLb[npt] * 2, LbOverBpPbPb[npt], uncStatLb[npt], uncSystLbOvBpPbPb[npt]);
    }
    Printf("\n \n \n");

    TGraphErrors *grLbOvBpstat = new TGraphErrors(nptbinsLb, ptbinCentersLb, LbOverBpPbPb, ptbinHalfwidthsLb, uncStatLb);
    grLbOvBpstat->SetLineColor(kBlack);
    grLbOvBpstat->SetLineWidth(2);
    grLbOvBpstat->SetMarkerStyle(21);
    grLbOvBpstat->SetMarkerColor(kGray + 2);
    grLbOvBpstat->GetYaxis()->SetRangeUser(0., 10);
    grLbOvBpstat->GetXaxis()->SetRangeUser(0., 27);
    grLbOvBpstat->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
    grLbOvBpstat->GetYaxis()->SetTitle("#Lambda_{b}/B^{+}");
    grLbOvBpstat->SetTitle(" ");

    TGraphErrors *grLbOvBpsyst = new TGraphErrors(nptbinsLb, ptbinCentersLb, LbOverBpPbPb, xwidthsForSystLb, uncSystLbOvBpPbPb);
    grLbOvBpsyst->SetLineColor(kGray + 2);
    grLbOvBpsyst->SetLineWidth(2);
    grLbOvBpsyst->SetMarkerStyle(21);
    grLbOvBpsyst->SetMarkerColor(kBlack);
    grLbOvBpsyst->GetXaxis()->SetRangeUser(0., 27);
    grLbOvBpsyst->GetYaxis()->SetRangeUser(0., 10);
    grLbOvBpsyst->SetFillStyle(0);

    TCanvas *clcovD = new TCanvas("clcovD", "clcovD", 500, 700);

    clcovD->SetTickx();
    clcovD->SetTicky();
    grLbOvBpstat->Draw("APz");
    grLbOvBpsyst->Draw("pE2");

    if (drawModels)
    {
        Double_t xmodels[18] = {0, 0.13, 0.43, 0.96, 1.4, 1.8, 2.1, 2.5, 2.8, 3.2, 3.5, 3.9, 4.2, 4.6, 4.9, 5.2, 5.5, 5.9};
        TH1D *Ko3 = new TH1D("KO3", "kO3", 17, xmodels);
        TH1D *Ko2 = new TH1D("KO2", "kO2", 17, xmodels);
        TH1D *pythia = new TH1D("pythia", "pythia", 17, xmodels);

        Double_t vKo2[17] = {8.2933, 8.4874, 8.6387, 8.7473, 8.8558, 8.9215, 8.9444, 8.9242, 8.7971, 8.7342, 8.5426, 8.3511, 8.0952, 7.8393, 7.5405, 7.2845, 7.0284};
        Double_t vKo3[17] = {5.0477, 5.1963, 5.4511, 5.5564, 5.6835, 5.8748, 5.9803, 6.0646, 6.1489, 6.2119, 6.2321, 6.1666, 6.1654, 6.0788, 5.992, 5.8627, 5.7116};
        Double_t vpythia[17];
        for (Int_t i = 0; i < 17; i++)
        {
            vpythia[i] = 0.8;
            Ko2->SetBinContent(i + 1, vKo2[i]);
            Ko2->SetBinError(i + 1, 0);
            Ko3->SetBinError(i + 1, 0);
            Ko3->SetBinContent(i + 1, vKo3[i]);
            pythia->SetBinContent(i + 1, vpythia[i]);
            pythia->SetBinError(i + 1, 0);
        }

        Ko2->SetLineColor(kBlue);
        Ko2->SetLineStyle(3);
        Ko2->SetMarkerColor(kBlue);
        Ko2->SetMarkerStyle(3);
        Ko2->SetMarkerStyle(20);

        Ko3->SetLineColor(kRed);
        Ko3->SetLineStyle(3);
        Ko3->SetTitle("Ko three-quark model");
        Ko2->SetTitle("Ko diquark model");

        pythia->SetLineColor(kGreen);
        pythia->SetLineStyle(3);
        pythia->SetMarkerColor(kGreen);
        pythia->SetMarkerStyle(21);
        pythia->SetTitle("PYTHIA");

        TF1 *f3 = new TF1("f3", "landaun", 0, 6);
        Ko3->Fit("f3", "LLR0");
        TF1 *f2 = new TF1("f2", "landaun", 0, 6);
        Ko2->Fit("f2", "LLR0");
        TF1 *f1 = new TF1("f1", "pol0", 0, 6);
        pythia->Fit("f1", "LLR0");
        const int npar = 3;
        Double_t p3[npar], p2[npar];
        ;
        for (Int_t i = 0; i < npar; i++)
        {
            p3[i] = f3->GetParameter(i);
            p2[i] = f2->GetParameter(i);
            cout << " parameters " << p3[i] << endl;
            cout << " parameters2 " << p2[i] << endl;
        }

        TF1 *f3extr = new TF1("f3extr", "landaun", 0, 20);
        f3extr->SetParameters(p3[0], p3[1], p3[2]);
        TF1 *f2extr = new TF1("f2extr", "landaun", 0, 20);
        f2extr->SetParameters(p2[0], p2[1], p2[2]);

        f3extr->SetLineColor(kRed);
        f3extr->SetTitle("Ko extr three-quark");
        f3extr->SetLineStyle(2);
        f2extr->SetLineColor(kBlue);
        f2extr->SetLineStyle(2);
        f2extr->SetTitle("Ko extr diquark");

        f2->SetLineColor(kBlue);
        f2->SetLineStyle(1);
        f2->SetLineWidth(3);
        f2->Draw("same");
        f3->SetLineColor(kRed);
        f3->SetLineStyle(1);
        f3->SetLineWidth(3);
        f3->Draw("same");
        //Ko3->Draw("same");
        //Ko2->Draw("same");
        f1->SetLineColor(kGreen);
        f1->SetLineStyle(1);
        f1->SetLineWidth(3);
        f1->Draw(" same");
        f3extr->Draw(" same");
        f2extr->Draw(" same");

        TLegend *leg = new TLegend(0.39, 0.45, 0.81, 0.84);
        leg->AddEntry("grLbOvBpstat", "#Lambda_{b}/B^{+}");
        leg->AddEntry("f3", "Ko three-quark model", "l"); //k03
        leg->AddEntry("f2", "Ko diquark model", "l");     //k02
        leg->AddEntry("f1", "PYTHIA", "l");
        leg->AddEntry("f3extr", "Ko extr three-quark", "l");
        leg->AddEntry("f2extr", "Ko extr diquark", "l");

        leg->Draw();
        clcovD->Modified();
        clcovD->cd();
        clcovD->SetSelected(clcovD);
    }
}
