# Publicar no GitHub pelo navegador

Não precisa de instalar Git nem usar comandos. O pacote exterior contém:

- **REPOSITORIO**: o conteúdo a carregar na página do código.
- **PARA_RELEASE**: o ZIP de instalação e SHA256SUMS para anexar à Release.

## 1. Criar o repositório

1. Entre na sua conta em https://github.com.
2. Abra https://github.com/new.
3. Nome: **BaetaCalc**.
4. Descrição sugerida: **Scientific and graphing calculator for RGDS+ / Linux Stock OS — PT/EN**.
5. Escolha **Public**. Pode criar Private se quiser rever primeiro.
6. Não peça ao GitHub para gerar README, licença ou .gitignore: já estão no pacote.
7. Carregue em **Create repository**.

## 2. Carregar o código

1. Extraia primeiro o ZIP recebido no Windows; não carregue o ZIP fechado.
2. Na página do repositório vazio, escolha **uploading an existing file**.
   Num repositório com ficheiros: **Add file → Upload files**.
3. Abra **REPOSITORIO** no Explorador de Ficheiros. Selecione TODO O CONTEÚDO
   dessa pasta e arraste-o para a área de carregamento do GitHub.
4. O resultado deve ter **README.md na raiz**, junto de src, tests, assets,
   launcher, scripts, docs, Makefile, LICENSE e restantes ficheiros.
   Não arraste a pasta exterior REPOSITORIO como uma pasta adicional.
5. Confirme que .gitignore e .gitattributes também foram incluídos.
6. Mensagem de commit sugerida: **Initial public release — BaetaCalc 2.5**.
7. Carregue em **Commit changes**. A página principal passa a mostrar o README
   com as imagens e a ligação para inglês.

O pacote contém menos de 100 ficheiros no repositório; cada ficheiro é inferior
à quota de 25 MiB do carregamento pelo navegador. Se preferir, carregue em lotes.

## 3. Criar a Release instalável

1. Abra **Releases**, na lateral da página do repositório.
2. Escolha **Draft a new release** / **Create a new release**.
3. Em **Choose a tag**, escreva **v2.5.0** e crie a tag sobre a branch principal.
4. Título: **BaetaCalc 2.5 — for RGDS+**.
5. Para a descrição, copie o conteúdo de **REPOSITORIO/docs/RELEASE_v2.5.0.md**.
6. Na área dos anexos, carregue estes DOIS ficheiros de **PARA_RELEASE**:
   - BaetaCalc_2_5_Final_PT_EN_RGDSPlus.zip
   - SHA256SUMS
7. Não anexe o ZIP exterior BaetaCalc_GitHub_Pronto.zip nem a pasta REPOSITORIO.
8. Pode usar **Save draft** para rever. Quando quiser tornar a Release pública,
   carregue em **Publish release** e confirme que aparece como a versão mais recente.
9. Abra o ZIP pelo link da Release e confirme a presença da pasta APPS.

## 4. Opcional

- Em About, use a descrição sugerida e tópicos como `rgdsplus`, `calculator`,
  `scientific-calculator`, `linux`, `sdl2`, `graphing-calculator`.
- Use Issues para receber problemas. Não publique logs ou configurações pessoais
  sem os rever.

## Licença escolhida

Foi preparada a licença MIT para o código original em nome de Filipe Baeta.
Permite utilização, modificação e redistribuição, incluindo comercial, conservando
os avisos de copyright e licença. A fonte continua com a licença própria.
A licença está no pacote para poder ser revista antes da publicação.

## Documentação oficial consultada

- Upload: https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository
- Releases: https://docs.github.com/en/repositories/releasing-projects-on-github/managing-releases-in-a-repository
- MIT: https://opensource.org/license/mit
