PGDMP     !                     |            StardewValley    15.4    15.4 B    r           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            s           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            t           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            u           1262    16817    StardewValley    DATABASE     �   CREATE DATABASE "StardewValley" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'English_United States.1252';
    DROP DATABASE "StardewValley";
                postgres    false            �            1259    16835 	   Abilitate    TABLE     �   CREATE TABLE public."Abilitate" (
    id_abilitate integer NOT NULL,
    nume character varying,
    nivel integer,
    avantaj character varying
);
    DROP TABLE public."Abilitate";
       public         heap    postgres    false            �            1259    16929    Animal    TABLE     �   CREATE TABLE public."Animal" (
    id_animal integer NOT NULL,
    nume character varying,
    specie character varying,
    stare character varying,
    id_cladire integer NOT NULL
);
    DROP TABLE public."Animal";
       public         heap    postgres    false            �            1259    16922    Cladire    TABLE       CREATE TABLE public."Cladire" (
    id_cladire integer NOT NULL,
    nume character varying,
    tip character varying,
    stare character varying,
    capacitate integer,
    cerinte_constructie character varying,
    cerinte_actualizare character varying
);
    DROP TABLE public."Cladire";
       public         heap    postgres    false            �            1259    16876    Inventar    TABLE     d   CREATE TABLE public."Inventar" (
    id_inventar integer NOT NULL,
    spatiu_disponibil integer
);
    DROP TABLE public."Inventar";
       public         heap    postgres    false            �            1259    16818    Jucator    TABLE     �   CREATE TABLE public."Jucator" (
    id_jucator integer NOT NULL,
    nume character varying,
    buget integer,
    id_inventar integer NOT NULL
);
    DROP TABLE public."Jucator";
       public         heap    postgres    false            �            1259    16825    JucatorAbilitate    TABLE     o   CREATE TABLE public."JucatorAbilitate" (
    id_jucator integer NOT NULL,
    id_abilitate integer NOT NULL
);
 &   DROP TABLE public."JucatorAbilitate";
       public         heap    postgres    false            �            1259    16851    JucatorPersonaj    TABLE     �   CREATE TABLE public."JucatorPersonaj" (
    id_jucator integer NOT NULL,
    id_personaj integer NOT NULL,
    relatie character varying
);
 %   DROP TABLE public."JucatorPersonaj";
       public         heap    postgres    false            �            1259    16959    Mineral    TABLE     �   CREATE TABLE public."Mineral" (
    id_mineral integer NOT NULL,
    nume character varying,
    tip character varying,
    nivel_mina integer,
    sanse integer,
    id_inventar integer
);
    DROP TABLE public."Mineral";
       public         heap    postgres    false            �            1259    16887    Misiune    TABLE     �   CREATE TABLE public."Misiune" (
    id_misiune integer NOT NULL,
    titlu character varying,
    descriere character varying,
    status character varying,
    recompense character varying
);
    DROP TABLE public."Misiune";
       public         heap    postgres    false            �            1259    16908 	   MisiuneZi    TABLE     a   CREATE TABLE public."MisiuneZi" (
    id_misiune integer NOT NULL,
    id_zi integer NOT NULL
);
    DROP TABLE public."MisiuneZi";
       public         heap    postgres    false            �            1259    16863    Personaj    TABLE     �   CREATE TABLE public."Personaj" (
    id_personaj integer NOT NULL,
    nume character varying,
    dialog character varying,
    zi_de_nastere character varying,
    preferinte character varying
);
    DROP TABLE public."Personaj";
       public         heap    postgres    false            �            1259    16971    Planta    TABLE     �   CREATE TABLE public."Planta" (
    id_planta integer NOT NULL,
    nume character varying,
    timp_crestere integer,
    pret integer,
    sezon character varying,
    stare character varying,
    id_inventar integer
);
    DROP TABLE public."Planta";
       public         heap    postgres    false            �            1259    16941    ProdusAnimal    TABLE     �   CREATE TABLE public."ProdusAnimal" (
    id_produs integer NOT NULL,
    nume character varying,
    cost integer,
    calitate character varying,
    id_animal integer NOT NULL,
    id_inventar integer
);
 "   DROP TABLE public."ProdusAnimal";
       public         heap    postgres    false            �            1259    16901    Zi    TABLE     �   CREATE TABLE public."Zi" (
    id_zi integer NOT NULL,
    data integer,
    sezon character varying,
    evenimente character varying,
    stare character varying,
    vreme character varying
);
    DROP TABLE public."Zi";
       public         heap    postgres    false            �            1259    17711    misiune_evenimente    VIEW     9  CREATE VIEW public.misiune_evenimente AS
 SELECT "Misiune".titlu,
    "Zi".evenimente
   FROM ((public."Misiune"
     LEFT JOIN public."MisiuneZi" ON (("Misiune".id_misiune = "MisiuneZi".id_misiune)))
     JOIN public."Zi" ON (("MisiuneZi".id_zi = "Zi".id_zi)))
  WHERE (("Zi".evenimente)::text <> 'None'::text);
 %   DROP VIEW public.misiune_evenimente;
       public          postgres    false    220    222    222    221    220    221            �            1259    17707    relati_bune    VIEW     �  CREATE VIEW public.relati_bune AS
 SELECT "Jucator".nume AS nume_jucator,
    "Personaj".nume AS nume_personaj
   FROM ((public."Jucator"
     LEFT JOIN public."JucatorPersonaj" ON (("Jucator".id_jucator = "JucatorPersonaj".id_jucator)))
     JOIN public."Personaj" ON (("JucatorPersonaj".id_personaj = "Personaj".id_personaj)))
  WHERE (("JucatorPersonaj".relatie)::text = 'Good'::text);
    DROP VIEW public.relati_bune;
       public          postgres    false    217    217    218    218    214    214    217            �            1259    17703    resurse_materiale    VIEW       CREATE VIEW public.resurse_materiale AS
 SELECT ((( SELECT count(*) AS count
           FROM public."Planta") + ( SELECT count(*) AS count
           FROM public."Mineral")) + ( SELECT count(*) AS count
           FROM public."ProdusAnimal")) AS "?column?";
 $   DROP VIEW public.resurse_materiale;
       public          postgres    false    226    225    227            d          0    16835 	   Abilitate 
   TABLE DATA           I   COPY public."Abilitate" (id_abilitate, nume, nivel, avantaj) FROM stdin;
    public          postgres    false    216   S       l          0    16929    Animal 
   TABLE DATA           N   COPY public."Animal" (id_animal, nume, specie, stare, id_cladire) FROM stdin;
    public          postgres    false    224   �S       k          0    16922    Cladire 
   TABLE DATA           w   COPY public."Cladire" (id_cladire, nume, tip, stare, capacitate, cerinte_constructie, cerinte_actualizare) FROM stdin;
    public          postgres    false    223   
T       g          0    16876    Inventar 
   TABLE DATA           D   COPY public."Inventar" (id_inventar, spatiu_disponibil) FROM stdin;
    public          postgres    false    219   �T       b          0    16818    Jucator 
   TABLE DATA           I   COPY public."Jucator" (id_jucator, nume, buget, id_inventar) FROM stdin;
    public          postgres    false    214   %U       c          0    16825    JucatorAbilitate 
   TABLE DATA           F   COPY public."JucatorAbilitate" (id_jucator, id_abilitate) FROM stdin;
    public          postgres    false    215   �U       e          0    16851    JucatorPersonaj 
   TABLE DATA           M   COPY public."JucatorPersonaj" (id_jucator, id_personaj, relatie) FROM stdin;
    public          postgres    false    217   �U       n          0    16959    Mineral 
   TABLE DATA           Z   COPY public."Mineral" (id_mineral, nume, tip, nivel_mina, sanse, id_inventar) FROM stdin;
    public          postgres    false    226   V       h          0    16887    Misiune 
   TABLE DATA           U   COPY public."Misiune" (id_misiune, titlu, descriere, status, recompense) FROM stdin;
    public          postgres    false    220   �V       j          0    16908 	   MisiuneZi 
   TABLE DATA           8   COPY public."MisiuneZi" (id_misiune, id_zi) FROM stdin;
    public          postgres    false    222   �W       f          0    16863    Personaj 
   TABLE DATA           Z   COPY public."Personaj" (id_personaj, nume, dialog, zi_de_nastere, preferinte) FROM stdin;
    public          postgres    false    218   X       o          0    16971    Planta 
   TABLE DATA           c   COPY public."Planta" (id_planta, nume, timp_crestere, pret, sezon, stare, id_inventar) FROM stdin;
    public          postgres    false    227   ,Y       m          0    16941    ProdusAnimal 
   TABLE DATA           a   COPY public."ProdusAnimal" (id_produs, nume, cost, calitate, id_animal, id_inventar) FROM stdin;
    public          postgres    false    225   �Y       i          0    16901    Zi 
   TABLE DATA           L   COPY public."Zi" (id_zi, data, sezon, evenimente, stare, vreme) FROM stdin;
    public          postgres    false    221   8Z       �           2606    16841    Abilitate Abilitate_pkey 
   CONSTRAINT     d   ALTER TABLE ONLY public."Abilitate"
    ADD CONSTRAINT "Abilitate_pkey" PRIMARY KEY (id_abilitate);
 F   ALTER TABLE ONLY public."Abilitate" DROP CONSTRAINT "Abilitate_pkey";
       public            postgres    false    216            �           2606    16935    Animal Animal_pkey 
   CONSTRAINT     [   ALTER TABLE ONLY public."Animal"
    ADD CONSTRAINT "Animal_pkey" PRIMARY KEY (id_animal);
 @   ALTER TABLE ONLY public."Animal" DROP CONSTRAINT "Animal_pkey";
       public            postgres    false    224            �           2606    16928    Cladire Cladire_pkey 
   CONSTRAINT     ^   ALTER TABLE ONLY public."Cladire"
    ADD CONSTRAINT "Cladire_pkey" PRIMARY KEY (id_cladire);
 B   ALTER TABLE ONLY public."Cladire" DROP CONSTRAINT "Cladire_pkey";
       public            postgres    false    223            �           2606    16880    Inventar Inventar_pkey 
   CONSTRAINT     a   ALTER TABLE ONLY public."Inventar"
    ADD CONSTRAINT "Inventar_pkey" PRIMARY KEY (id_inventar);
 D   ALTER TABLE ONLY public."Inventar" DROP CONSTRAINT "Inventar_pkey";
       public            postgres    false    219            �           2606    16829 &   JucatorAbilitate JucatorAbilitate_pkey 
   CONSTRAINT     ~   ALTER TABLE ONLY public."JucatorAbilitate"
    ADD CONSTRAINT "JucatorAbilitate_pkey" PRIMARY KEY (id_jucator, id_abilitate);
 T   ALTER TABLE ONLY public."JucatorAbilitate" DROP CONSTRAINT "JucatorAbilitate_pkey";
       public            postgres    false    215    215            �           2606    16857 $   JucatorPersonaj JucatorPersonaj_pkey 
   CONSTRAINT     {   ALTER TABLE ONLY public."JucatorPersonaj"
    ADD CONSTRAINT "JucatorPersonaj_pkey" PRIMARY KEY (id_jucator, id_personaj);
 R   ALTER TABLE ONLY public."JucatorPersonaj" DROP CONSTRAINT "JucatorPersonaj_pkey";
       public            postgres    false    217    217            �           2606    16895    Jucator Jucator_id_inventar_key 
   CONSTRAINT     e   ALTER TABLE ONLY public."Jucator"
    ADD CONSTRAINT "Jucator_id_inventar_key" UNIQUE (id_inventar);
 M   ALTER TABLE ONLY public."Jucator" DROP CONSTRAINT "Jucator_id_inventar_key";
       public            postgres    false    214            �           2606    16824    Jucator Jucator_pkey 
   CONSTRAINT     ^   ALTER TABLE ONLY public."Jucator"
    ADD CONSTRAINT "Jucator_pkey" PRIMARY KEY (id_jucator);
 B   ALTER TABLE ONLY public."Jucator" DROP CONSTRAINT "Jucator_pkey";
       public            postgres    false    214            �           2606    16965    Mineral Mineral_pkey 
   CONSTRAINT     ^   ALTER TABLE ONLY public."Mineral"
    ADD CONSTRAINT "Mineral_pkey" PRIMARY KEY (id_mineral);
 B   ALTER TABLE ONLY public."Mineral" DROP CONSTRAINT "Mineral_pkey";
       public            postgres    false    226            �           2606    16893    Misiune Misiune_pkey 
   CONSTRAINT     ^   ALTER TABLE ONLY public."Misiune"
    ADD CONSTRAINT "Misiune_pkey" PRIMARY KEY (id_misiune);
 B   ALTER TABLE ONLY public."Misiune" DROP CONSTRAINT "Misiune_pkey";
       public            postgres    false    220            �           2606    16869    Personaj Personaj_pkey 
   CONSTRAINT     a   ALTER TABLE ONLY public."Personaj"
    ADD CONSTRAINT "Personaj_pkey" PRIMARY KEY (id_personaj);
 D   ALTER TABLE ONLY public."Personaj" DROP CONSTRAINT "Personaj_pkey";
       public            postgres    false    218            �           2606    16977    Planta Planta_pkey 
   CONSTRAINT     [   ALTER TABLE ONLY public."Planta"
    ADD CONSTRAINT "Planta_pkey" PRIMARY KEY (id_planta);
 @   ALTER TABLE ONLY public."Planta" DROP CONSTRAINT "Planta_pkey";
       public            postgres    false    227            �           2606    16947    ProdusAnimal ProdusAnimal_pkey 
   CONSTRAINT     g   ALTER TABLE ONLY public."ProdusAnimal"
    ADD CONSTRAINT "ProdusAnimal_pkey" PRIMARY KEY (id_produs);
 L   ALTER TABLE ONLY public."ProdusAnimal" DROP CONSTRAINT "ProdusAnimal_pkey";
       public            postgres    false    225            �           2606    16907 
   Zi Zi_pkey 
   CONSTRAINT     O   ALTER TABLE ONLY public."Zi"
    ADD CONSTRAINT "Zi_pkey" PRIMARY KEY (id_zi);
 8   ALTER TABLE ONLY public."Zi" DROP CONSTRAINT "Zi_pkey";
       public            postgres    false    221            �           1259    16847    fki_Abilitate_JucatorAbilitate    INDEX     g   CREATE INDEX "fki_Abilitate_JucatorAbilitate" ON public."JucatorAbilitate" USING btree (id_abilitate);
 4   DROP INDEX public."fki_Abilitate_JucatorAbilitate";
       public            postgres    false    215            �           1259    16958    fki_Inventar_ProdusAnimal    INDEX     ]   CREATE INDEX "fki_Inventar_ProdusAnimal" ON public."ProdusAnimal" USING btree (id_inventar);
 /   DROP INDEX public."fki_Inventar_ProdusAnimal";
       public            postgres    false    225            �           1259    16886    fki_Jucator_Inventar    INDEX     S   CREATE INDEX "fki_Jucator_Inventar" ON public."Jucator" USING btree (id_inventar);
 *   DROP INDEX public."fki_Jucator_Inventar";
       public            postgres    false    214            �           1259    16875    fki_Personaj_JucatorPersonaj    INDEX     c   CREATE INDEX "fki_Personaj_JucatorPersonaj" ON public."JucatorPersonaj" USING btree (id_personaj);
 2   DROP INDEX public."fki_Personaj_JucatorPersonaj";
       public            postgres    false    217            �           1259    16921    fki_Zi_MisiuneZi    INDEX     K   CREATE INDEX "fki_Zi_MisiuneZi" ON public."MisiuneZi" USING btree (id_zi);
 &   DROP INDEX public."fki_Zi_MisiuneZi";
       public            postgres    false    222            �           2606    16842 +   JucatorAbilitate Abilitate_JucatorAbilitate    FK CONSTRAINT     �   ALTER TABLE ONLY public."JucatorAbilitate"
    ADD CONSTRAINT "Abilitate_JucatorAbilitate" FOREIGN KEY (id_abilitate) REFERENCES public."Abilitate"(id_abilitate) NOT VALID;
 Y   ALTER TABLE ONLY public."JucatorAbilitate" DROP CONSTRAINT "Abilitate_JucatorAbilitate";
       public          postgres    false    215    216    3245            �           2606    16936    Animal Animal_Cladire    FK CONSTRAINT     �   ALTER TABLE ONLY public."Animal"
    ADD CONSTRAINT "Animal_Cladire" FOREIGN KEY (id_cladire) REFERENCES public."Cladire"(id_cladire);
 C   ALTER TABLE ONLY public."Animal" DROP CONSTRAINT "Animal_Cladire";
       public          postgres    false    223    224    3259            �           2606    16953 "   ProdusAnimal Inventar_ProdusAnimal    FK CONSTRAINT     �   ALTER TABLE ONLY public."ProdusAnimal"
    ADD CONSTRAINT "Inventar_ProdusAnimal" FOREIGN KEY (id_inventar) REFERENCES public."Inventar"(id_inventar) NOT VALID;
 P   ALTER TABLE ONLY public."ProdusAnimal" DROP CONSTRAINT "Inventar_ProdusAnimal";
       public          postgres    false    225    219    3252            �           2606    16896    Jucator Jucator_Inventar    FK CONSTRAINT     �   ALTER TABLE ONLY public."Jucator"
    ADD CONSTRAINT "Jucator_Inventar" FOREIGN KEY (id_inventar) REFERENCES public."Inventar"(id_inventar) NOT VALID;
 F   ALTER TABLE ONLY public."Jucator" DROP CONSTRAINT "Jucator_Inventar";
       public          postgres    false    214    219    3252            �           2606    16830 )   JucatorAbilitate Jucator_JucatorAbilitate    FK CONSTRAINT     �   ALTER TABLE ONLY public."JucatorAbilitate"
    ADD CONSTRAINT "Jucator_JucatorAbilitate" FOREIGN KEY (id_jucator) REFERENCES public."Jucator"(id_jucator);
 W   ALTER TABLE ONLY public."JucatorAbilitate" DROP CONSTRAINT "Jucator_JucatorAbilitate";
       public          postgres    false    215    3239    214            �           2606    16858 '   JucatorPersonaj Jucator_JucatorPersonaj    FK CONSTRAINT     �   ALTER TABLE ONLY public."JucatorPersonaj"
    ADD CONSTRAINT "Jucator_JucatorPersonaj" FOREIGN KEY (id_jucator) REFERENCES public."Jucator"(id_jucator);
 U   ALTER TABLE ONLY public."JucatorPersonaj" DROP CONSTRAINT "Jucator_JucatorPersonaj";
       public          postgres    false    214    217    3239            �           2606    16966    Mineral Mineral_Inventar    FK CONSTRAINT     �   ALTER TABLE ONLY public."Mineral"
    ADD CONSTRAINT "Mineral_Inventar" FOREIGN KEY (id_inventar) REFERENCES public."Inventar"(id_inventar);
 F   ALTER TABLE ONLY public."Mineral" DROP CONSTRAINT "Mineral_Inventar";
       public          postgres    false    226    219    3252            �           2606    16911    MisiuneZi Misiune_MisiuneZi    FK CONSTRAINT     �   ALTER TABLE ONLY public."MisiuneZi"
    ADD CONSTRAINT "Misiune_MisiuneZi" FOREIGN KEY (id_misiune) REFERENCES public."Misiune"(id_misiune);
 I   ALTER TABLE ONLY public."MisiuneZi" DROP CONSTRAINT "Misiune_MisiuneZi";
       public          postgres    false    222    220    3254            �           2606    16870 (   JucatorPersonaj Personaj_JucatorPersonaj    FK CONSTRAINT     �   ALTER TABLE ONLY public."JucatorPersonaj"
    ADD CONSTRAINT "Personaj_JucatorPersonaj" FOREIGN KEY (id_personaj) REFERENCES public."Personaj"(id_personaj) NOT VALID;
 V   ALTER TABLE ONLY public."JucatorPersonaj" DROP CONSTRAINT "Personaj_JucatorPersonaj";
       public          postgres    false    217    218    3250            �           2606    16978    Planta Planta_Inventar    FK CONSTRAINT     �   ALTER TABLE ONLY public."Planta"
    ADD CONSTRAINT "Planta_Inventar" FOREIGN KEY (id_inventar) REFERENCES public."Inventar"(id_inventar);
 D   ALTER TABLE ONLY public."Planta" DROP CONSTRAINT "Planta_Inventar";
       public          postgres    false    227    3252    219            �           2606    16948     ProdusAnimal ProdusAnimal_Animal    FK CONSTRAINT     �   ALTER TABLE ONLY public."ProdusAnimal"
    ADD CONSTRAINT "ProdusAnimal_Animal" FOREIGN KEY (id_animal) REFERENCES public."Animal"(id_animal);
 N   ALTER TABLE ONLY public."ProdusAnimal" DROP CONSTRAINT "ProdusAnimal_Animal";
       public          postgres    false    3261    224    225            �           2606    16916    MisiuneZi Zi_MisiuneZi    FK CONSTRAINT     �   ALTER TABLE ONLY public."MisiuneZi"
    ADD CONSTRAINT "Zi_MisiuneZi" FOREIGN KEY (id_zi) REFERENCES public."Zi"(id_zi) NOT VALID;
 D   ALTER TABLE ONLY public."MisiuneZi" DROP CONSTRAINT "Zi_MisiuneZi";
       public          postgres    false    222    3256    221            d      x�}�1�0���9���B�� �� �.Qp�C0rP{}�V]Y�>��v����,�߄���^FT��Qc�����;���}���`��4Ur;-]����B�e�T6��*e��s�9/�˳޳1���=W      l   V   x��0�����N�t�/�t��O�47�0��M,�L�L��;%���,�9C��KJM8}R�P���t'��p�� Mɀ+����� ��G      k   �   x�}бn�0�����������9$&ԭ����"�#���BTh���u�e�9l��`�B���6ں
��6K�b
}��w�CND�3"�x��ȇ)&����G�Sck�
��bҀ�&T�,:7A3*�������79��gp���%�����7T[R���il<ñ3�U�+{SG��նooO�wb�1������<��V����`�� G�S      g   !   x�3�44�2�46�2�L8�L�LA�=... ?6�      b   T   x�˱
�0����0�4�#��.�.�t(Z��7�;~a���W���H8a����b�r�9�����7
��fXk�fc(�U�#      c   &   x�340�42�240�42�P�@�"h�id����� |��      e   2   x�340�44�t��O�2�MalcNC#N�Dӈ��&lR����� �k�      n   |   x�u�1
1D����	d�`+H��	����X��7���0�c�y��'J_��''u˕%��'�A��U]�%��VÌ�#BV�	�Źp}�>e��#���%��jڹ|;�"���*}      h   2  x�U�AO�0��鯰v�K�Z&q��MmB�#�к���.��i��t+���<�}�vҙyauR���;�w�^M� J� TQ�0Kb�u�̦SX:B.|MtB�n��9H	j�No�@Z�1 w,��[��ɤXE��Œ����,���_�VQ�^�W�J\�VC��SSg&��f�G�yG�נ5�Je#↎?��&F��\B˧��w�xJ��v�7��16Q�#�1��{P�(�l`0��=:��tn�YG���ط�%YhC�����J���&�#�b�V�� )��ig����<��GQ���{      j   "   x�36�41�26�41�26��F\Ʀ 2F��� ]�      f     x�=�AO�0���xܧ�G4�&�4!qIWo1K��IVu��tH��`�=�{MC�<H�Le�܈�3Ɛa͉��6�ф�CȊ�賗4������x�g��eձj��Z񴰶�k|Y�E�ٹ��A�E9�d92v.����ԛ7����s��њ[�O�3N�o|b��w��״�X��^U����͑��Q�	N<)JQ��g�q�}��\]h��ވ�MfX�7�t�I��A$b�ҕ��.9%�9���%K
ZR�=L�M��B�(�v�������ݝ�X      o   �   x�e̱�0F���O�J{����f�,��;В����EƓ|9l�I^cX�`�%�8�bX��a�+ti�-�ƹ< &�h�j,.*��;��N�Ћ�s�4�xͳ濰Č^}q�q�IѠ������'"� R<2�      m   j   x�e�A@0����S8�h��w ���֦AhT$%�O��r�����+��h��Y#�˿(b��)P�~��7���왼�|�s���� �h�3�aI�ygٗ��)�ߝ!      i   �   x�U��
�0E盧�ISt�t���K�!�_B~�ހq��p���S]W�p��B9ry13���b��c �3u1�L�m'z1�CP��1��-:FC��E$x�)&G'k;erq���un� ~��Qق�:
Ov�1���E9z     