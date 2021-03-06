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
#include "TGraphAsymmErrors.h"
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
void plotRAAv2Charm()
{
    ///////////////
    //prompt D0 RAA
    ///////////////

    TFile *fD = new TFile("D0RAAprompt_TDR.root");
    TCanvas *cc = (TCanvas *)fD->Get("cRAAprompt");

    TList *list = cc->GetListOfPrimitives();
    TH1F *hRaaPrompt = (TH1F *)list->FindObject("hRaaPrompt");
    Double_t x[11], y[11], exl[11], eyl[11], exh[11], eyh[11];
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
    FILE *fDout = fopen("fCharmPrompt.txt", "w");
    //pt,RAA,ex,stat,syst
    fprintf(fDout, "D0 (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst low, err syst high \n \n \n");
    TGraphAsymmErrors *grD0Raasyst = new TGraphAsymmErrors(11);
    grD0Raasyst->SetFillStyle(0);
    grD0Raasyst->SetLineColor(1);
    hRaaPrompt->SetMinimum(0);
    hRaaPrompt->SetMaximum(2);
    hRaaPrompt->SetTitle(0);

    TLatex *texD0 = new TLatex(4, 1.8, "0-10% Pb-Pb, #sqrt{s_{NN}}=5.5 TeV, L_{int} = 10 nb^{-1}");
    texD0->SetTextFont(42);
    texD0->SetTextSize(0.05);
    TLatex *texD02 = new TLatex(4, 1.6, "D^{0}#rightarrow K^{-} #pi^{+}");
    texD02->SetTextFont(42);
    texD02->SetTextSize(0.04);

    TCanvas *can = new TCanvas("can", "can", 600, 500);
    can->SetLeftMargin(0.13);
    can->SetBottomMargin(0.13);
    hRaaPrompt->Draw();
    grD0Raasyst->Draw("2same");
    texD0->Draw();
    texD02->Draw();

    for (Int_t ii = 0; ii < 11; ii++)
    {
        fprintf(fDout, "%f, %f, %f, %f, %f , %f \n", x[ii], hRaaPrompt->GetBinWidth(ii + 1), y[ii], hRaaPrompt->GetBinError(ii + 1), eyl[ii], eyh[ii]);
        grD0Raasyst->SetPoint(ii, x[ii], y[ii]);
        grD0Raasyst->SetPointError(ii, exl[ii], exh[ii], eyl[ii], eyh[ii]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    ///////////////
    //prompt Ds RAA
    ///////////////

    TFile *fDs = new TFile("../Ds/Ds_RAA_stat_010.root");
    TCanvas *ccs = (TCanvas *)fDs->Get("canvasRAA");

    TList *lists = ccs->GetListOfPrimitives();
    TH1F *hRaaDs = (TH1F *)lists->FindObject("hRAA_Ds");

    Double_t xs[11], ys[11], exls[11], eyls[11], exhs[11], eyhs[11];
    TGraphErrors *grDsRaasyst = new TGraphErrors(11);
    grDsRaasyst->SetFillStyle(0);
    grDsRaasyst->SetLineColor(kRed);
    for (Int_t ii = 0; ii < 11; ii++)
    {
        xs[ii] = hRaaDs->GetBinCenter(ii + 1);
        ys[ii] = hRaaDs->GetBinContent(ii + 1);
        exls[ii] = 0.2;
        exhs[ii] = 0.2;

        for (Int_t jj = 0; jj < 11; jj++)
        {
            if (xs[ii] >= (x[jj] - hRaaPrompt->GetBinWidth(jj + 1) / 2) && xs[ii] < (x[jj] + hRaaPrompt->GetBinWidth(jj + 1) / 2))
            {
                cout << "*** ii=" << ii << "  xs[ii]=" << xs[ii] << "  jj="
                     << jj << " x[jj]=" << x[jj] << "  range:" << x[jj] - hRaaPrompt->GetBinWidth(jj + 1) / 2 << "-" << x[jj] + hRaaPrompt->GetBinWidth(jj + 1) / 2 << endl;

                eyls[ii] = ys[ii] * eyl[jj] / y[jj];
                eyhs[ii] = ys[ii] * eyh[jj] / y[jj];
                cout << ys[ii] << "  " << eyl[jj] << " " << y[jj] << endl;
                cout << ys[ii] << "  " << eyh[jj] << " " << y[jj] << endl;
                grDsRaasyst->SetPoint(ii, xs[ii], ys[ii]);
                grDsRaasyst->SetPointError(ii, exls[ii], eyls[ii]); //symmetric
            }
        }
    }
    hRaaDs->GetYaxis()->SetTitleOffset(1.15);

    TLatex *texDs = new TLatex(4, 1.8, "0-10% Pb-Pb, #sqrt{s_{NN}}=5.5 TeV, L_{int} = 10 nb^{-1}");
    texDs->SetTextFont(42);
    texDs->SetTextSize(0.05);
    TLatex *texDs2 = new TLatex(4, 1.6, "D_{s}^{+}#rightarrow K^{+} K^{-} #pi^{+}");
    texDs2->SetTextFont(42);
    texDs2->SetTextSize(0.04);

    TCanvas *cans = new TCanvas("cans", "cans", 600, 500);
    cans->SetLeftMargin(0.13);
    cans->SetBottomMargin(0.13);
    //hForDrawing->Draw();
    hRaaDs->Draw();
    grDsRaasyst->Draw("2same");
    texDs->Draw();
    texDs2->Draw();

    fprintf(fDout, "Ds (0-10%% centr., Lint=10nb-1): pt, width x, RAA, err stat, err syst low, err syst high \n \n \n");
    for (Int_t ii = 0; ii < 11; ii++)
    {
        fprintf(fDout, "%f, %f, %f, %f, %f , %f \n", xs[ii], hRaaDs->GetBinWidth(ii + 1), ys[ii], hRaaDs->GetBinError(ii + 1), eyls[ii], eyhs[ii]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    ///////////////////
    //   Lc/D ratio
    ///////////////////

    Double_t nev = 1.6e+10;
    const Int_t nptbinsLc = 6;
    Double_t ptbinsLc[nptbinsLc + 1] = {2., 4., 5., 6., 8., 10., 20.};
    Double_t ptbinCentersLc[nptbinsLc] = {3., 4.5, 5.5, 7., 9., 15.};
    Double_t ptbinHalfwidthsLc[nptbinsLc] = {1., .5, .5, 1., 1., 5.};
    Double_t xwidthsForSystLc[nptbinsLc] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25};

    Double_t LcOverD0PbPb[nptbinsLc] = {1.2, 0.7, 0.35, 0.1, 0.1, 0.1};
    Double_t signifEvUnLcPbPb[nptbinsLc] = {6e-05, 1.6e-4, 1.4e-4, 1.8e-4, 2.4e-4, 4.8e-4};
    Double_t uncLcOvD0PbPb[7] = {
        0.02, //tracking efficiency
        0.05, // PID
        0.05, // yield extr
        0.07, // MC corr
        0.03, // MC pt shape
        0.2,  // Feeddown
        0.05  // branching ratio
    };

    Double_t totuncLcOvD0PbPb;
    for (Int_t ii = 0; ii < 7; ii++)
    {
        totuncLcOvD0PbPb += uncLcOvD0PbPb[ii] * uncLcOvD0PbPb[ii];
    }
    totuncLcOvD0PbPb = TMath::Sqrt(totuncLcOvD0PbPb);
    printf("Unc Lc/D0 -> %f \n", totuncLcOvD0PbPb); //0.23, including B.R.
    fprintf(fDout, "Lc (0-20%% centr., Lint=10nb-1): pt, width x, Lc/D0, err stat, err syst \n \n \n");

    Double_t uncStatLc[nptbinsLc];
    Double_t uncSystLcOvD0PbPb[nptbinsLc];
    for (Int_t npt = 0; npt < nptbinsLc; npt++)
    {
        uncSystLcOvD0PbPb[npt] = totuncLcOvD0PbPb * LcOverD0PbPb[npt];
        uncStatLc[npt] = 1. / (signifEvUnLcPbPb[npt] * TMath::Sqrt(nev)) * LcOverD0PbPb[npt]; //PbPb
        fprintf(fDout, "%f, %f, %f, %f, %f \n", ptbinCentersLc[npt], ptbinHalfwidthsLc[npt] * 2, LcOverD0PbPb[npt], uncStatLc[npt], uncSystLcOvD0PbPb[npt]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    TGraphErrors *grLcOvD0stat = new TGraphErrors(nptbinsLc, ptbinCentersLc, LcOverD0PbPb, ptbinHalfwidthsLc, uncStatLc);
    grLcOvD0stat->SetLineColor(kBlack);
    grLcOvD0stat->SetLineWidth(2);
    grLcOvD0stat->SetMarkerStyle(21);
    grLcOvD0stat->SetMarkerColor(kBlue);
    grLcOvD0stat->GetYaxis()->SetRangeUser(0., 2);
    grLcOvD0stat->GetYaxis()->SetTitle("#Lambda_{c}/D^{0}");
    grLcOvD0stat->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    grLcOvD0stat->SetTitle(" ");

    TGraphErrors *grLcOvD0syst = new TGraphErrors(nptbinsLc, ptbinCentersLc, LcOverD0PbPb, xwidthsForSystLc, uncSystLcOvD0PbPb);
    grLcOvD0syst->SetLineColor(kBlue);
    grLcOvD0syst->SetLineWidth(2);
    grLcOvD0syst->SetMarkerStyle(21);
    grLcOvD0syst->SetMarkerColor(kBlack);
    grLcOvD0syst->SetFillStyle(0);

    TCanvas *clcovD = new TCanvas("clcovD", "clcovD", 700, 700);
    clcovD->SetTickx();
    clcovD->SetTicky();
    grLcOvD0stat->Draw("APz");
    grLcOvD0syst->Draw("pE2");

    /////////////////////////////////
    /////////////////////////////////
    /////////////////////////////////
    //========== v2  =============
    /////////////////////////////////
    /////////////////////////////////

    ///////////////
    //prompt D0 v2
    ///////////////

    TFile *ffv2 = new TFile("../HFv2/D0DsLc_v2_TDR.root");

    TCanvas *ccv2 = (TCanvas *)ffv2->Get("cv2Prompt");

    TList *listv2 = ccv2->GetListOfPrimitives();

    gStyle->SetOptStat(0);

    //D0
    Double_t xv2[31], yv2[31], exv2[31], eyv2[31], exsyst[31];
    //numerical values from BAMPS
    xv2[0] = 0.25;
    yv2[0] = 0.025;
    exv2[0] = 0;
    eyv2[0] = 0.0115641;
    xv2[1] = 0.75;
    yv2[1] = 0.1;
    exv2[1] = 0;
    eyv2[1] = 0.00510037;
    xv2[2] = 1.25;
    yv2[2] = 0.15;
    exv2[2] = 0;
    eyv2[2] = 0.000841262;
    xv2[3] = 1.75;
    yv2[3] = 0.18;
    exv2[3] = 0;
    eyv2[3] = 0.000750804;
    xv2[4] = 2.25;
    yv2[4] = 0.210001;
    exv2[4] = 0;
    eyv2[4] = 0.000537289;
    xv2[5] = 2.75;
    yv2[5] = 0.215;
    exv2[5] = 0;
    eyv2[5] = 0.000505821;
    xv2[6] = 3.25;
    yv2[6] = 0.205;
    exv2[6] = 0;
    eyv2[6] = 0.000470271;
    xv2[7] = 3.75;
    yv2[7] = 0.19;
    exv2[7] = 0;
    eyv2[7] = 0.000440249;
    xv2[8] = 4.25;
    yv2[8] = 0.175;
    exv2[8] = 0;
    eyv2[8] = 0.000429682;
    xv2[9] = 4.75;
    yv2[9] = 0.155;
    exv2[9] = 0;
    eyv2[9] = 0.000420091;
    xv2[10] = 5.25;
    yv2[10] = 0.148;
    exv2[10] = 0;
    eyv2[10] = 0.000463785;
    xv2[11] = 5.75;
    yv2[11] = 0.13;
    exv2[11] = 0;
    eyv2[11] = 0.000465731;
    xv2[12] = 6.25;
    yv2[12] = 0.126;
    exv2[12] = 0;
    eyv2[12] = 0.000571007;
    xv2[13] = 6.75;
    yv2[13] = 0.125;
    exv2[13] = 0;
    eyv2[13] = 0.000601186;
    xv2[14] = 7.25;
    yv2[14] = 0.11;
    exv2[14] = 0;
    eyv2[14] = 0.000636443;
    xv2[15] = 7.75;
    yv2[15] = 0.11;
    exv2[15] = 0;
    eyv2[15] = 0.00067388;
    xv2[16] = 8.25;
    yv2[16] = 0.105;
    exv2[16] = 0;
    eyv2[16] = 0.00076441;
    xv2[17] = 8.75;
    yv2[17] = 0.1;
    exv2[17] = 0;
    eyv2[17] = 0.000805322;
    xv2[18] = 9.25;
    yv2[18] = 0.1;
    exv2[18] = 0;
    eyv2[18] = 0.000850062;
    xv2[19] = 9.75;
    yv2[19] = 0.085;
    exv2[19] = 0;
    eyv2[19] = 0.000902122;
    xv2[20] = 10.25;
    yv2[20] = 0.075;
    exv2[20] = 0;
    eyv2[20] = 0.000959761;
    xv2[21] = 10.75;
    yv2[21] = 0.075;
    exv2[21] = 0;
    eyv2[21] = 0.00102375;
    xv2[22] = 11.25;
    yv2[22] = 0.07;
    exv2[22] = 0;
    eyv2[22] = 0.00109752;
    xv2[23] = 11.75;
    yv2[23] = 0.07;
    exv2[23] = 0;
    eyv2[23] = 0.0011524;
    xv2[24] = 12.25;
    yv2[24] = 0.07;
    exv2[24] = 0;
    eyv2[24] = 0.00109752;
    xv2[25] = 12.75;
    yv2[25] = 0.07;
    exv2[25] = 0;
    eyv2[25] = 0.0011524;
    xv2[26] = 13.25;
    yv2[26] = 0.07;
    exv2[26] = 0;
    eyv2[26] = 0.00121305;
    xv2[27] = 13.75;
    yv2[27] = 0.07;
    exv2[27] = 0;
    eyv2[27] = 0.00128044;
    xv2[28] = 14.25;
    yv2[28] = 0.07;
    exv2[28] = 0;
    eyv2[28] = 0.00135576;
    xv2[29] = 14.75;
    yv2[29] = 0.07;
    exv2[29] = 0;
    eyv2[29] = 0.0014405;
    xv2[30] = 15.25;
    yv2[30] = 0.07;
    exv2[30] = 0;
    eyv2[30] = 0.00153653;

    //Double_t erryield = 0.004; //Run2 is ~0.006-0.03 in 30-50%
    // Double_t erryield = 0.01;

    //Double_t errfd;
    Double_t uncv2[31];
    TGraphErrors *grD0v2syst = new TGraphErrors(31);
    fprintf(fDout, "D0 (30-50%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");
    Double_t fdfrac = 0.1;                                                                                                                                                          //assumption based on Run2, in all pt bin (not so valid at low pt, but here it is used only for pt>2)
    Double_t yierr[2] = {0.05, 0.01};                                                                                                                                               //1% in all pt range in 3050%                                                                                                                                             // in %  //0-2,>2
                                                                                                                                                                                    //  Double_t fderr[5] = {0.005, 0.01, 0.015, 0.02};        //absolute values in 0-0.5,0.5-1,1-1.5,1.5-2,>2 GeV/c  -- (~10% valore del v2 nel bin)
    Double_t fderr[6] = {0.1, 0.13 * fdfrac / (1 - fdfrac), 0.1 * fdfrac / (1 - fdfrac), 0.08 * fdfrac / (1 - fdfrac), 0.05 * fdfrac / (1 - fdfrac), 0.03 * fdfrac / (1 - fdfrac)}; //relative values in 0-2 (here it is 10% of v2 value),2-3, 3-4,4-6,6-12, 12-16 (these are from unc on f_fd on yield extraction, not supposed to cancel in v2 formula)

    for (Int_t ii = 0; ii < 31; ii++)
    {
        exsyst[ii] = 0.1;
        Double_t relerr, errfd, erryield;
        if (xv2[ii] < 2) //low pt<2 GeV/c
        {
            erryield = yierr[0];
            Double_t erryieldonv2 = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1. - 4 * yv2[ii] / TMath::Pi() * 4 * yv2[ii] / TMath::Pi()) * erryield;

            //Double_t erryieldonv2 = TMath::Pi() / 4. * (1 - (4 * yv2[ii] / TMath::Pi()) * (4 * yv2[ii] / TMath::Pi())) / TMath::Sqrt(1 - yv2[ii] * yv2[ii]) * erryield;
            //Double_t erryieldonv2 = TMath::Pi() / 4. * (1 - (4 * yv2[ii] / TMath::Pi()) * (4 * yv2[ii] / TMath::Pi())) / TMath::Sqrt(1 - yv2[ii] * yv2[ii]) * erryield;

            errfd = fderr[0];
            uncv2[ii] = TMath::Sqrt((errfd * yv2[ii]) * (errfd * yv2[ii]) + erryieldonv2 * erryieldonv2); //sum in quadrature of absolute uncert of fd and yield
            cout << "***** erryieldonv2Abs=" << erryieldonv2 << "  errfdabs=" << errfd * yv2[ii] << "  uncv2[ii]=" << uncv2[ii] << endl;
        }
        else
        {
            erryield = yierr[1];
            // 2 - 3, 3 - 4, 4 - 6, 6 - 12, 12 - 16
            //for fd, using uncertainties on fd due to yield extraction of non prompt
            if (xv2[ii] >= 2 && xv2[ii] < 3)
                errfd = fderr[1];
            else if (xv2[ii] >= 3 && xv2[ii] < 4)
                errfd = fderr[2];
            else if (xv2[ii] >= 4 && xv2[ii] < 6)
                errfd = fderr[3];
            else if (xv2[ii] >= 6 && xv2[ii] < 12)
                errfd = fderr[4];
            else if (xv2[ii] >= 12)
                errfd = fderr[5];

            relerr = TMath::Sqrt(erryield * erryield + errfd * errfd);
            //uncv2[ii] = TMath::Pi() / 4. * (1 - (4 * yv2[ii] / TMath::Pi()) * (4 * yv2[ii] / TMath::Pi())) / TMath::Sqrt(1 - yv2[ii] * yv2[ii]) * relerr;
            uncv2[ii] = TMath::Pi() / 4. / TMath::Sqrt(2.) * (1. - 4 * yv2[ii] / TMath::Pi() * 4 * yv2[ii] / TMath::Pi()) * relerr;
        }
        // if (ii < 4)
        //     errfd = 0.02; //Run2 is ~0.02 at low pt. 0.02 nel 4 bin 0.005, 0.01, 0.015, 0.02 (10% valore del v2 nel bin?)
        //                   //errfd = 0.1;
        // else
        //     errfd = 0.005;
        // //  errfd = 0.05;
        // relerr = TMath::Sqrt(erryield * erryield + errfd * errfd);
        //cout << "pt=" << xv2[ii] << "   erryield=" << erryield << "   erryieldAbs=" << erryield * yv2[ii] << "  errfd=" << errfd << "  errfdAbs=" << errfd * yv2[ii] << "  relerr=" << relerr << endl;
        //  cout << "v2 D0 -> " << ii << "  " << yv2[ii] << " " << TMath::Pi() / 4. * (1 - (4 * yv2[ii] / TMath::Pi()) * (4 * yv2[ii] / TMath::Pi())) / TMath::Sqrt(1 - yv2[ii] * yv2[ii]) * relerr << endl;

        //      uncv2[ii] = TMath::Sqrt(erryield * erryield + errfd * errfd);
        cout
            << "D0  --> " << ii << "  " << xv2[ii] << "  " << yv2[ii] << "  " << exsyst[ii] << "  " << uncv2[ii] << endl;
        grD0v2syst->SetPoint(ii, xv2[ii], yv2[ii]);
        grD0v2syst->SetPointError(ii, exsyst[ii], uncv2[ii]);
        fprintf(fDout, "%f, %f, %f, %f, %f \n", xv2[ii], 0.5, yv2[ii], eyv2[ii], uncv2[ii]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    exsyst[0] = 0.1;
    exsyst[30] = 0.1;
    grD0v2syst->SetFillStyle(0);
    grD0v2syst->SetLineColor(1);
    TGraphErrors *grD0v2 = new TGraphErrors(31, xv2, yv2, exv2, eyv2);
    grD0v2->SetMarkerStyle(21);
    grD0v2->SetMarkerColor(1);
    grD0v2->SetMarkerSize(1.);
    grD0v2->SetLineWidth(2);

    ///////////////
    //prompt Ds v2
    ///////////////

    TH1F *hEllipticFlowDs = (TH1F *)listv2->FindObject("hEllipticFlow");
    hEllipticFlowDs->SetMarkerSize(1.);
    hEllipticFlowDs->SetTitle("");
    hEllipticFlowDs->GetYaxis()->SetTitle("v_{2}");
    hEllipticFlowDs->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    hEllipticFlowDs->GetYaxis()->SetTitleOffset(1.2);
    hEllipticFlowDs->GetXaxis()->SetLabelSize(0.05);
    hEllipticFlowDs->GetYaxis()->SetLabelSize(0.05);
    hEllipticFlowDs->SetMaximum(0.25);
    hEllipticFlowDs->GetXaxis()->SetRangeUser(0, 16);
    Int_t nDs = hEllipticFlowDs->GetNbinsX();
    Double_t *xDs = new Double_t[nDs];
    Double_t *yDs = new Double_t[nDs];
    Double_t *uncv2Ds = new Double_t[nDs];
    Double_t *exsystDs = new Double_t[nDs];

    fprintf(fDout, "Ds (30-50%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");

    for (Int_t ii = 0; ii < nDs; ii++)
    {
        xDs[ii] = hEllipticFlowDs->GetBinCenter(ii + 1);
        yDs[ii] = hEllipticFlowDs->GetBinContent(ii + 1);
        exsystDs[ii] = 0.1;
        Double_t errfdDs;           //no points below 2 GeV, as D0
        Double_t erryieldDs = 0.01; //as D0

        if (xDs[ii] >= 2 && xDs[ii] < 3)
            errfdDs = fderr[1]; //taken from D0 ones above
        else if (xDs[ii] >= 3 && xDs[ii] < 4)
            errfdDs = fderr[2];
        else if (xDs[ii] >= 4 && xDs[ii] < 6)
            errfdDs = fderr[3];
        else if (xDs[ii] >= 6 && xDs[ii] < 12)
            errfdDs = fderr[4];
        else if (xDs[ii] >= 12)
            errfdDs = fderr[5];

        Double_t relerrDs = TMath::Sqrt(erryieldDs * erryieldDs + errfdDs * errfdDs);
        uncv2Ds[ii] = TMath::Pi() / 4. * (1 - (4 * yDs[ii] / TMath::Pi()) * (4 * yDs[ii] / TMath::Pi())) / TMath::Sqrt(1 - yDs[ii] * yDs[ii]) * relerrDs;

        cout << "Ds  --> " << ii << "  " << xDs[ii] << "  " << yDs[ii] << "  " << uncv2Ds[ii] << endl;
        fprintf(fDout, "%f, %f, %f, %f, %f \n", xDs[ii], hRaaDs->GetBinWidth(ii + 1), yDs[ii], hEllipticFlowDs->GetBinError(ii + 1), uncv2Ds[ii]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    TGraphErrors *grDsv2syst = new TGraphErrors(nDs, xDs, yDs, exsystDs, uncv2Ds);
    grDsv2syst->SetFillStyle(0);
    grDsv2syst->SetLineColor(2);

    ///////////////
    //prompt Lc v2
    ///////////////

    Double_t xLc[3], yLc[3], exLc[3], eyLc[3];
    xLc[0] = 4.36751;
    yLc[0] = 0.156789;
    exLc[0] = 1.5;
    eyLc[0] = 0.0304761;
    xLc[1] = 7.92788;
    yLc[1] = 0.11213;
    exLc[1] = 2;
    eyLc[1] = 0.0329896;
    xLc[2] = 13.0141;
    yLc[2] = 0.0794759;
    exLc[2] = 3;
    eyLc[2] = 0.0191216;

    TGraphErrors *grLcv2 = new TGraphErrors(3, xLc, yLc, exLc, eyLc);
    grLcv2->SetMarkerStyle(23);
    grLcv2->SetMarkerColor(kGreen + 2);
    grLcv2->SetLineColor(kGreen + 2);
    grLcv2->SetLineWidth(2);
    grLcv2->SetMarkerSize(1.);
    // Double_t errfdLc = 0.05;
    //Double_t erryieldLc = 0.01;
    Double_t errfdLc = 0.2;     //relative error from TDR on Yield. I consider 20% on v2 (i do not propagate it with the formula)
    Double_t erryieldLc = 0.05; //relative error

    Double_t uncv2Lc[3], exsystLc[3];
    TGraphErrors *grLcv2syst = new TGraphErrors(3);
    grLcv2syst->SetFillStyle(0);
    grLcv2syst->SetLineColor(kGreen + 2);

    fprintf(fDout, "Lambdac (10-40%% centr., Lint=10nb-1): pt, width x, v2, err stat, err syst \n \n \n");

    for (Int_t ii = 0; ii < 3; ii++)
    {
        exsystLc[ii] = 0.1;
        Double_t erryieldonv2 = TMath::Pi() / 4. * (1 - (4 * yLc[ii] / TMath::Pi()) * (4 * yLc[ii] / TMath::Pi())) / TMath::Sqrt(1 - yLc[ii] * yLc[ii]) * erryieldLc;

        uncv2Lc[ii] = TMath::Sqrt(erryieldLc * erryieldLc + errfdLc * yLc[ii] * errfdLc * yLc[ii]);
        grLcv2syst->SetPoint(ii, xLc[ii], yLc[ii]);
        grLcv2syst->SetPointError(ii, exsystLc[ii], uncv2Lc[ii]);
        fprintf(fDout, "%f, %f, %f, %f, %f \n", xLc[ii], exLc[ii] * 2, yLc[ii], eyLc[ii], uncv2Lc[ii]);
    }
    fprintf(fDout, "\n \n \n");
    fprintf(fDout, "================");
    fprintf(fDout, "\n \n \n");

    TLatex *tex = new TLatex(4., 0.23, "Pb-Pb, #sqrt{s_{NN}}=5.5 TeV, L_{int} = 10 nb^{-1}");
    tex->SetTextFont(42);
    tex->SetLineWidth(2);
    TLegend *leg = new TLegend(0.5, 0.65, 0.88, 0.8);
    leg->AddEntry(grD0v2, "D^{0}, 30-50% centr.", "p");
    leg->AddEntry(hEllipticFlowDs, "D^{+}_{s}, 30-50% centr.", "p");
    leg->AddEntry(grLcv2, "#Lambda_{c}^{+}, 10-40% centr.", "p");
    leg->SetTextFont(42);
    leg->SetLineWidth(2);
    leg->SetBorderSize(0);

    TCanvas *canv2 = new TCanvas("canv2", "canv2", 600, 500);
    canv2->SetLeftMargin(0.13);
    canv2->SetBottomMargin(0.13);
    //hForDrawing->Draw();
    hEllipticFlowDs->Draw();

    grD0v2->Draw("Pzsame");
    grD0v2syst->Draw("2same");
    hEllipticFlowDs->Draw("same");
    grDsv2syst->Draw("2same");

    grLcv2->Draw("Pzsame");
    grLcv2syst->Draw("2same");
    tex->Draw();
    leg->Draw();
}
