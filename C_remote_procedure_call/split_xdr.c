/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "split.h"

bool_t
xdr_abonnement (XDR *xdrs, abonnement *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->prix))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_utilisateur (XDR *xdrs, utilisateur *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->email, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->adresse, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->motdepasse, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->liste_abo, 10,
		sizeof (abonnement), (xdrproc_t) xdr_abonnement))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nb_abo))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_offre (XDR *xdrs, offre *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_abonnement (xdrs, &objp->abo))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->prix_partage))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_evaluation (XDR *xdrs, evaluation *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_utilisateur (xdrs, &objp->user))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->note))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->commentaire, 255,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gestion_abonnement (XDR *xdrs, gestion_abonnement *objp)
{
	register int32_t *buf;

	 if (!xdr_utilisateur (xdrs, &objp->user))
		 return FALSE;
	 if (!xdr_abonnement (xdrs, &objp->abo))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_partage_abonnement (XDR *xdrs, partage_abonnement *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_utilisateur (xdrs, &objp->user))
			 return FALSE;
		 if (!xdr_offre (xdrs, &objp->partage))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->co_abonnes, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->co_abonnes;
					i < 10; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_utilisateur (xdrs, &objp->user))
			 return FALSE;
		 if (!xdr_offre (xdrs, &objp->partage))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->co_abonnes, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->co_abonnes;
					i < 10; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_utilisateur (xdrs, &objp->user))
		 return FALSE;
	 if (!xdr_offre (xdrs, &objp->partage))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->co_abonnes, 10,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_select_partage (XDR *xdrs, select_partage *objp)
{
	register int32_t *buf;

	 if (!xdr_utilisateur (xdrs, &objp->user))
		 return FALSE;
	 if (!xdr_partage_abonnement (xdrs, &objp->selectionne))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_search (XDR *xdrs, search *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 40,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->prix_max))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_note (XDR *xdrs, note *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_utilisateur (xdrs, &objp->user))
		 return FALSE;
	 if (!xdr_evaluation (xdrs, &objp->eval))
		 return FALSE;
	return TRUE;
}
