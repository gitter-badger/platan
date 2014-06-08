#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QVector>
#include <QLocale>
#include <QDebug>

QVector<QLocale::Country> getAllCountries();

QString getCountryCode(QLocale::Country c)
{
    switch (c)
    {
    case QLocale::AnyCountry:
        return "ZZ";
    case QLocale::Afghanistan:
        return "AF";
    case QLocale::Albania:
        return "AL";
    case QLocale::Algeria:
        return "DZ";
    case QLocale::AmericanSamoa:
        return "AS";
    case QLocale::Andorra:
        return "AD";
    case QLocale::Angola:
        return "AO";
    case QLocale::Anguilla:
        return "AI";
    case QLocale::Antarctica:
        return "AQ";
    case QLocale::AntiguaAndBarbuda:
        return "AG";
    case QLocale::Argentina:
        return "AR";
    case QLocale::Armenia:
        return "AM";
    case QLocale::Aruba:
        return "AW";
    case QLocale::Australia:
        return "AU";
    case QLocale::Austria:
        return "AT";
    case QLocale::Azerbaijan:
        return "AZ";
    case QLocale::Bahamas:
        return "BS";
    case QLocale::Bahrain:
        return "BH";
    case QLocale::Bangladesh:
        return "BD";
    case QLocale::Barbados:
        return "BB";
    case QLocale::Belarus:
        return "BY";
    case QLocale::Belgium:
        return "BE";
    case QLocale::Belize:
        return "BZ";
    case QLocale::Benin:
        return "BJ";
    case QLocale::Bermuda:
        return "BM";
    case QLocale::Bhutan:
        return "BT";
    case QLocale::Bolivia:
        return "BO";
    case QLocale::BosniaAndHerzegowina:
        return "BA";
    case QLocale::Botswana:
        return "BW";
    case QLocale::BouvetIsland:
        return "BV";
    case QLocale::Brazil:
        return "BR";
    case QLocale::BritishIndianOceanTerritory:
        return "IO";
    case QLocale::Brunei:
        return "BN";
    case QLocale::Bulgaria:
        return "BG";
    case QLocale::BurkinaFaso:
        return "BF";
    case QLocale::Burundi:
        return "BI";
    case QLocale::Cambodia:
        return "KH";
    case QLocale::Cameroon:
        return "CM";
    case QLocale::Canada:
        return "CA";
    case QLocale::CapeVerde:
        return "CV";
    case QLocale::CaymanIslands:
        return "KY";
    case QLocale::CentralAfricanRepublic:
        return "CF";
    case QLocale::Chad:
        return "TD";
    case QLocale::Chile:
        return "CL";
    case QLocale::China:
        return "CN";
    case QLocale::ChristmasIsland:
        return "CX";
    case QLocale::CocosIslands:
        return "CC";
    case QLocale::Colombia:
        return "CO";
    case QLocale::Comoros:
        return "KM";
    case QLocale::CongoKinshasa:
        return "CD";
    case QLocale::CongoBrazzaville:
        return "CG";
    case QLocale::CookIslands:
        return "CK";
    case QLocale::CostaRica:
        return "CR";
    case QLocale::IvoryCoast:
        return "CI";
    case QLocale::Croatia:
        return "HR";
    case QLocale::Cuba:
        return "CU";
    case QLocale::Cyprus:
        return "CY";
    case QLocale::CzechRepublic:
        return "CZ";
    case QLocale::Denmark:
        return "DK";
    case QLocale::Djibouti:
        return "DJ";
    case QLocale::Dominica:
        return "DM";
    case QLocale::DominicanRepublic:
        return "DO";
    case QLocale::EastTimor:
        return "TL";
    case QLocale::Ecuador:
        return "EC";
    case QLocale::Egypt:
        return "EG";
    case QLocale::ElSalvador:
        return "SV";
    case QLocale::EquatorialGuinea:
        return "GQ";
    case QLocale::Eritrea:
        return "ER";
    case QLocale::Estonia:
        return "EE";
    case QLocale::Ethiopia:
        return "ET";
    case QLocale::FalklandIslands:
        return "FK";
    case QLocale::FaroeIslands:
        return "FO";
    case QLocale::Fiji:
        return "FJ";
    case QLocale::Finland:
        return "FI";
    case QLocale::France:
        return "FR";
    case QLocale::Guernsey:
        return "GG";
    case QLocale::FrenchGuiana:
        return "GF";
    case QLocale::FrenchPolynesia:
        return "PF";
    case QLocale::FrenchSouthernTerritories:
        return "TF";
    case QLocale::Gabon:
        return "GA";
    case QLocale::Gambia:
        return "GM";
    case QLocale::Georgia:
        return "GE";
    case QLocale::Germany:
        return "DE";
    case QLocale::Ghana:
        return "GH";
    case QLocale::Gibraltar:
        return "GI";
    case QLocale::Greece:
        return "GR";
    case QLocale::Greenland:
        return "GL";
    case QLocale::Grenada:
        return "GD";
    case QLocale::Guadeloupe:
        return "GP";
    case QLocale::Guam:
        return "GU";
    case QLocale::Guatemala:
        return "GT";
    case QLocale::Guinea:
        return "GN";
    case QLocale::GuineaBissau:
        return "GW";
    case QLocale::Guyana:
        return "GY";
    case QLocale::Haiti:
        return "HT";
    case QLocale::HeardAndMcDonaldIslands:
        return "HM";
    case QLocale::Honduras:
        return "HN";
    case QLocale::HongKong:
        return "HK";
    case QLocale::Hungary:
        return "HU";
    case QLocale::Iceland:
        return "IS";
    case QLocale::India:
        return "IN";
    case QLocale::Indonesia:
        return "ID";
    case QLocale::Iran:
        return "IR";
    case QLocale::Iraq:
        return "IQ";
    case QLocale::Ireland:
        return "IE";
    case QLocale::Israel:
        return "IL";
    case QLocale::Italy:
        return "IT";
    case QLocale::Jamaica:
        return "JM";
    case QLocale::Japan:
        return "JP";
    case QLocale::Jordan:
        return "JO";
    case QLocale::Kazakhstan:
        return "KZ";
    case QLocale::Kenya:
        return "KE";
    case QLocale::Kiribati:
        return "KI";
    case QLocale::NorthKorea:
        return "KP";
    case QLocale::SouthKorea:
        return "KR";
    case QLocale::Kuwait:
        return "KW";
    case QLocale::Kyrgyzstan:
        return "KG";
    case QLocale::Laos:
        return "LA";
    case QLocale::Latvia:
        return "LV";
    case QLocale::Lebanon:
        return "LB";
    case QLocale::Lesotho:
        return "LS";
    case QLocale::Liberia:
        return "LR";
    case QLocale::Libya:
        return "LY";
    case QLocale::Liechtenstein:
        return "LI";
    case QLocale::Lithuania:
        return "LT";
    case QLocale::Luxembourg:
        return "LU";
    case QLocale::Macau:
        return "MO";
    case QLocale::Macedonia:
        return "MK";
    case QLocale::Madagascar:
        return "MG";
    case QLocale::Malawi:
        return "MW";
    case QLocale::Malaysia:
        return "MY";
    case QLocale::Maldives:
        return "MV";
    case QLocale::Mali:
        return "ML";
    case QLocale::Malta:
        return "MT";
    case QLocale::MarshallIslands:
        return "MH";
    case QLocale::Martinique:
        return "MQ";
    case QLocale::Mauritania:
        return "MR";
    case QLocale::Mauritius:
        return "MU";
    case QLocale::Mayotte:
        return "YT";
    case QLocale::Mexico:
        return "MX";
    case QLocale::Micronesia:
        return "FM";
    case QLocale::Moldova:
        return "MD";
    case QLocale::Monaco:
        return "MC";
    case QLocale::Mongolia:
        return "MN";
    case QLocale::Montserrat:
        return "MS";
    case QLocale::Morocco:
        return "MA";
    case QLocale::Mozambique:
        return "MZ";
    case QLocale::Myanmar:
        return "MM";
    case QLocale::Namibia:
        return "NA";
    case QLocale::NauruCountry:
        return "NR";
    case QLocale::Nepal:
        return "NP";
    case QLocale::Netherlands:
        return "NL";
    case QLocale::CuraSao:
        return "CW";
    case QLocale::NewCaledonia:
        return "NC";
    case QLocale::NewZealand:
        return "NZ";
    case QLocale::Nicaragua:
        return "NI";
    case QLocale::Niger:
        return "NE";
    case QLocale::Nigeria:
        return "NG";
    case QLocale::Niue:
        return "NU";
    case QLocale::NorfolkIsland:
        return "NF";
    case QLocale::NorthernMarianaIslands:
        return "MP";
    case QLocale::Norway:
        return "NO";
    case QLocale::Oman:
        return "OM";
    case QLocale::Pakistan:
        return "PK";
    case QLocale::Palau:
        return "PW";
    case QLocale::PalestinianTerritories:
        return "PS";
    case QLocale::Panama:
        return "PA";
    case QLocale::PapuaNewGuinea:
        return "PG";
    case QLocale::Paraguay:
        return "PY";
    case QLocale::Peru:
        return "PE";
    case QLocale::Philippines:
        return "PH";
    case QLocale::Pitcairn:
        return "PN";
    case QLocale::Poland:
        return "PL";
    case QLocale::Portugal:
        return "PT";
    case QLocale::PuertoRico:
        return "PR";
    case QLocale::Qatar:
        return "QA";
    case QLocale::Reunion:
        return "RE";
    case QLocale::Romania:
        return "RO";
    case QLocale::Russia:
        return "RU";
    case QLocale::Rwanda:
        return "RW";
    case QLocale::SaintKittsAndNevis:
        return "KN";
    case QLocale::SaintLucia:
        return "LC";
    case QLocale::SaintVincentAndTheGrenadines:
        return "VC";
    case QLocale::Samoa:
        return "WS";
    case QLocale::SanMarino:
        return "SM";
    case QLocale::SaoTomeAndPrincipe:
        return "ST";
    case QLocale::SaudiArabia:
        return "SA";
    case QLocale::Senegal:
        return "SN";
    case QLocale::Seychelles:
        return "SC";
    case QLocale::SierraLeone:
        return "SL";
    case QLocale::Singapore:
        return "SG";
    case QLocale::Slovakia:
        return "SK";
    case QLocale::Slovenia:
        return "SI";
    case QLocale::SolomonIslands:
        return "SB";
    case QLocale::Somalia:
        return "SO";
    case QLocale::SouthAfrica:
        return "ZA";
    case QLocale::SouthGeorgiaAndTheSouthSandwichIslands:
        return "GS";
    case QLocale::Spain:
        return "ES";
    case QLocale::SriLanka:
        return "LK";
    case QLocale::SaintHelena:
        return "SH";
    case QLocale::SaintPierreAndMiquelon:
        return "PM";
    case QLocale::Sudan:
        return "SD";
    case QLocale::Suriname:
        return "SR";
    case QLocale::SvalbardAndJanMayenIslands:
        return "SJ";
    case QLocale::Swaziland:
        return "SZ";
    case QLocale::Sweden:
        return "SE";
    case QLocale::Switzerland:
        return "CH";
    case QLocale::Syria:
        return "SY";
    case QLocale::Taiwan:
        return "TW";
    case QLocale::Tajikistan:
        return "TJ";
    case QLocale::Tanzania:
        return "TZ";
    case QLocale::Thailand:
        return "TH";
    case QLocale::Togo:
        return "TG";
    case QLocale::Tokelau:
        return "TK";
    case QLocale::Tonga:
        return "TO";
    case QLocale::TrinidadAndTobago:
        return "TT";
    case QLocale::Tunisia:
        return "TN";
    case QLocale::Turkey:
        return "TR";
    case QLocale::Turkmenistan:
        return "TM";
    case QLocale::TurksAndCaicosIslands:
        return "TC";
    case QLocale::Tuvalu:
        return "TV";
    case QLocale::Uganda:
        return "UG";
    case QLocale::Ukraine:
        return "UA";
    case QLocale::UnitedArabEmirates:
        return "AE";
    case QLocale::UnitedKingdom:
        return "GB";
    case QLocale::UnitedStates:
        return "US";
    case QLocale::UnitedStatesMinorOutlyingIslands:
        return "UM";
    case QLocale::Uruguay:
        return "UY";
    case QLocale::Uzbekistan:
        return "UZ";
    case QLocale::Vanuatu:
        return "VU";
    case QLocale::VaticanCityState:
        return "VA";
    case QLocale::Venezuela:
        return "VE";
    case QLocale::Vietnam:
        return "VN";
    case QLocale::BritishVirginIslands:
        return "VG";
    case QLocale::UnitedStatesVirginIslands:
        return "VI";
    case QLocale::WallisAndFutunaIslands:
        return "WF";
    case QLocale::WesternSahara:
        return "EH";
    case QLocale::Yemen:
        return "YE";
    case QLocale::CanaryIslands:
        return "IC";
    case QLocale::Zambia:
        return "ZM";
    case QLocale::Zimbabwe:
        return "ZW";
    case QLocale::ClippertonIsland:
        return "CP";
    case QLocale::Montenegro:
        return "ME";
    case QLocale::Serbia:
        return "RS";
    case QLocale::SaintBarthelemy:
        return "BL";
    case QLocale::SaintMartin:
        return "MF";
    case QLocale::LatinAmericaAndTheCaribbean:
        return "419";
    case QLocale::AscensionIsland:
        return "AC";
    case QLocale::AlandIslands:
        return "AX";
    case QLocale::DiegoGarcia:
        return "DG";
    case QLocale::CeutaAndMelilla:
        return "EA";
    case QLocale::IsleOfMan:
        return "IM";
    case QLocale::Jersey:
        return "JE";
    case QLocale::TristanDaCunha:
        return "TA";
    case QLocale::SouthSudan:
        return "SS";
    case QLocale::Bonaire:
        return "BQ";
    case QLocale::SintMaarten:
        return "SX";
    case QLocale::Kosovo:
        return "XK";
    }
    return QString();
}

class CountryData
{
public:
    CountryData()
    {}
    CountryData(QLocale::Country l)
    {
        name = QLocale::countryToString(l);
        for (int i = 1; i < name.length(); ++ i)
            if (name.at(i).isUpper())
                name.insert(i++, " ");
        code = getCountryCode(l).toLower();
    }

    QString name;
    QString code;
    bool operator==(const CountryData &other) const
    {
        return name == other.name;
    }

    bool operator!=(const CountryData &other) const
    {
        return name == other.name;
    }

    bool operator<(const CountryData &other) const
    {
        return name < other.name;
    }

    bool operator>(const CountryData &other) const
    {
        return name > other.name;
    }

    bool operator<=(const CountryData &other) const
    {
        return name <= other.name;
    }

    bool operator>=(const CountryData &other) const
    {
        return name >= other.name;
    }
};

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    QVector<CountryData> countryDatas;
    for (auto country : getAllCountries())
        countryDatas.append(CountryData(country));
    qDebug() << getCountryCode(QLocale::Germany);
    qDebug() << getCountryCode(QLocale::Austria);
    qSort(countryDatas);
    for (CountryData data : countryDatas)
    {
        QString res(":/icons/icons/%1.png");
        res = res.arg(data.code);
        ui->comboBox->addItem(QIcon(res), data.name);
    }
    ui->comboBox->setCurrentIndex(-1);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

QVector<QLocale::Country> getAllCountries()
{
    QVector<QLocale::Country> result;
    for (int i = 1; i <= QLocale::LastCountry; ++i)
    {
        QLocale::Country c = (QLocale::Country)i;
        if (c != QLocale::Antarctica)
            result.push_back(c);
    }
    return result;
}
