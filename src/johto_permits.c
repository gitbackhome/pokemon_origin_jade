#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "string_util.h"
#include "johto_permits.h"
#include "hoenn_licenses.h"
#include "constants/region_map_sections.h"
#include "constants/vars_origin_jade.h"

// Eigene Bitmaske in VAR_JOHTO_PERMITS, unabhaengig von FLAG_BADGE01-08.
// Die teilen sich Kanto und Johto: Rocko setzt FLAG_BADGE01_GET, Falkner
// ebenfalls. Wer aus Kanto kommt, hat alle acht - eine Ordenabfrage in Johto
// geht deshalb immer durch. Die Sperre greift ausschliesslich innerhalb von
// Johto (IsJohtoMapsec); in Hoenn gelten die Lizenzen, in Kanto die
// FRLG-Ordensschwellen aus field_move.c.

#if defined(POKEMON_HNS)

bool32 IsJohtoMapsec(u32 mapSecId)
{
    // Zusammenhaengender Johto-Block der HnS-Mapsection-Liste (Neuborkia bis
    // Strudelinseln); Route 26/27/28, Tohjo-Faelle, Silberberg und die
    // Siegesstrasse zur Johto-Liga liegen mit darin.
    return mapSecId >= JOHTO_MAPSEC_START && mapSecId <= JOHTO_MAPSEC_END;
}

bool32 HasJohtoPermit(u32 index)
{
    if (index >= PERM_COUNT)
        return FALSE;
    return (VarGet(VAR_JOHTO_PERMITS) & (1 << index)) != 0;
}

// Anreisekorridor aus Kanto: Route 26, Route 27 und die Tohjo-Faelle.
// Hier gelten die Befugnisse NICHT. Route 27 laesst sich nur mit dem Surfer
// durchqueren, und die Befugnis dafuer vergibt Morty - vierter Orden, tief in
// Johto. Mit Sperre kaeme man also gar nicht erst nach Neuborkia.
// Auf dem Rueckweg zur Liga faellt die Ausnahme nicht auf: bis dahin sind
// alle Befugnisse laengst vergeben.
static bool32 IsJohtoArrivalCorridor(u32 mapSecId)
{
    return mapSecId == MAPSEC_ROUTE_26
        || mapSecId == MAPSEC_ROUTE_27
        || mapSecId == MAPSEC_TOHJO_FALLS;
}

bool32 JohtoPermitsApply(void)
{
    u32 mapSecId = gMapHeader.regionMapSectionId;

    if (IsJohtoArrivalCorridor(mapSecId))
        return FALSE;
    return IsJohtoMapsec(mapSecId);
}

// Special: Befugnisindex (0 - PERM_COUNT-1) in gSpecialVar_0x8004
void SetJohtoPermit(void)
{
    if (gSpecialVar_0x8004 < PERM_COUNT)
        VarSet(VAR_JOHTO_PERMITS, VarGet(VAR_JOHTO_PERMITS) | (1 << gSpecialVar_0x8004));
}

#else

bool32 IsJohtoMapsec(u32 mapSecId) { return FALSE; }
bool32 HasJohtoPermit(u32 index) { return TRUE; }
bool32 JohtoPermitsApply(void) { return FALSE; }
void SetJohtoPermit(void) {}

#endif

// Special: Index in gSpecialVar_0x8004. Ergebnis nach gSpecialVar_Result:
// TRUE = darf hier eingesetzt werden. Die Indizes von LIC_* und PERM_* sind
// deckungsgleich, deshalb genuegt einer fuer beide Regionen. Ausserhalb von
// Hoenn und Johto immer TRUE, damit die Skripte in Kanto unveraendert
// durchlaufen.
void CheckFieldPermission(void)
{
    if (HoennLicensesApply())
        gSpecialVar_Result = HasHoennLicense(gSpecialVar_0x8004);
    else if (JohtoPermitsApply())
        gSpecialVar_Result = HasJohtoPermit(gSpecialVar_0x8004);
    else
        gSpecialVar_Result = TRUE;
}

// Special: legt das Wort der jeweiligen Region in STR_VAR_2 ab, damit die
// Absage nicht zweimal getextet werden muss. Beide sind weiblich, der
// Satzbau bleibt also gleich.
void BufferFieldPermissionTerm(void)
{
#if GERMAN
    static const u8 sText_HoennTerm[] = _("Erlaubnis");
    static const u8 sText_JohtoTerm[] = _("Befugnis");
#else
    static const u8 sText_HoennTerm[] = _("licence");
    static const u8 sText_JohtoTerm[] = _("permit");
#endif

    if (JohtoPermitsApply())
        StringCopy(gStringVar2, sText_JohtoTerm);
    else
        StringCopy(gStringVar2, sText_HoennTerm);
}
