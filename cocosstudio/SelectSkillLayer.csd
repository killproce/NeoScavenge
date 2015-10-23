<GameProjectFile>
  <PropertyGroup Type="Layer" Name="SelectSkillLayer" ID="2d88f42e-3218-4822-86d1-de128b5e9f76" Version="2.3.2.3" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" Tag="46" ctype="GameLayerObjectData">
        <Size X="1360.0000" Y="768.0000" />
        <Children>
          <AbstractNodeData Name="BgPanel" ActionTag="-200471577" Tag="51" IconVisible="False" LeftMargin="222.3285" RightMargin="937.6715" TopMargin="372.9188" BottomMargin="195.0812" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="200.0000" Y="200.0000" />
            <Children>
              <AbstractNodeData Name="GUIBG_3" ActionTag="-693924563" Tag="52" IconVisible="False" LeftMargin="-275.5883" RightMargin="-261.4117" TopMargin="-165.6779" BottomMargin="-174.3221" ctype="SpriteObjectData">
                <Size X="737.0000" Y="540.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="92.9117" Y="95.6779" />
                <Scale ScaleX="0.2937" ScaleY="0.3853" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4646" Y="0.4784" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="SelectSkill/GUIBG.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="222.3285" Y="195.0812" />
            <Scale ScaleX="5.6720" ScaleY="2.8715" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1635" Y="0.2540" />
            <PreSize X="0.1471" Y="0.2604" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="SelectTalent_BagPos" ActionTag="-440146969" Tag="54" IconVisible="True" LeftMargin="152.0776" RightMargin="1207.9224" TopMargin="29.4882" BottomMargin="738.5118" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="152.0776" Y="738.5118" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1118" Y="0.9616" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedTalent_BagPos" ActionTag="-1225718749" Tag="55" IconVisible="True" LeftMargin="873.4297" RightMargin="486.5703" TopMargin="29.4900" BottomMargin="738.5100" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="873.4297" Y="738.5100" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6422" Y="0.9616" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="GUIArrowRightSprite_up" ActionTag="723866744" Tag="56" IconVisible="False" LeftMargin="735.7155" RightMargin="601.2845" TopMargin="78.0232" BottomMargin="654.9768" ctype="SpriteObjectData">
            <Size X="23.0000" Y="35.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="747.2155" Y="672.4768" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5494" Y="0.8756" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="SelectSkill/GUIArrowRight.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ConfirmButton" ActionTag="1945586284" Tag="57" IconVisible="False" LeftMargin="711.0311" RightMargin="585.9689" TopMargin="210.8036" BottomMargin="531.1964" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="8" BottomEage="8" Scale9OriginX="15" Scale9OriginY="8" Scale9Width="33" Scale9Height="10" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="63.0000" Y="26.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="742.5311" Y="544.1964" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5460" Y="0.7086" />
            <PreSize X="0.0463" Y="0.0339" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Normal" Path="SelectSkill/btn_confirm.png" Plist="" />
            <PressedFileData Type="Normal" Path="SelectSkill/btn_confirm_dn.png" Plist="" />
            <NormalFileData Type="Normal" Path="SelectSkill/btn_confirm.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="RandomButton" ActionTag="-1341191006" Tag="58" IconVisible="False" LeftMargin="678.6019" RightMargin="555.3981" TopMargin="247.1265" BottomMargin="468.8735" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="96" Scale9Height="30" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="126.0000" Y="52.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="741.6019" Y="494.8735" />
            <Scale ScaleX="0.5051" ScaleY="0.5289" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5453" Y="0.6444" />
            <PreSize X="0.0926" Y="0.0677" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Normal" Path="SelectSkill/x2_btn_random_off.png" Plist="" />
            <PressedFileData Type="Normal" Path="SelectSkill/x2_btn_random_dn.png" Plist="" />
            <NormalFileData Type="Normal" Path="SelectSkill/x2_btn_random_off.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="GUIArrowRightSprite_down" ActionTag="-2055470813" Tag="59" IconVisible="False" LeftMargin="729.2264" RightMargin="607.7736" TopMargin="306.4497" BottomMargin="426.5503" ctype="SpriteObjectData">
            <Size X="23.0000" Y="35.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="740.7264" Y="444.0503" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5447" Y="0.5782" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="SelectSkill/GUIArrowRight.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedSkillPointLabel" ActionTag="-1617623979" Tag="60" IconVisible="False" LeftMargin="714.8112" RightMargin="589.1888" TopMargin="126.6260" BottomMargin="625.3740" FontSize="16" LabelText="使用：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="48.0000" Y="16.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="742.8112" Y="633.3740" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="2" G="196" B="2" />
            <PrePosition X="0.5462" Y="0.8247" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="LeftSkillPointLabel" ActionTag="602628123" Tag="61" IconVisible="False" LeftMargin="711.7075" RightMargin="584.2925" TopMargin="152.3875" BottomMargin="599.6125" FontSize="16" LabelText="剩余：" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="48.0000" Y="16.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="743.7075" Y="607.6125" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="2" G="196" B="2" />
            <PrePosition X="0.5468" Y="0.7912" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="SelectTalentText" ActionTag="-667625962" Tag="62" IconVisible="False" LeftMargin="161.4083" RightMargin="1008.5917" TopMargin="4.0022" BottomMargin="743.9978" FontSize="20" LabelText="可以选择的人物天赋." ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="190.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="256.4083" Y="753.9978" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1885" Y="0.9818" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="SelectFlawText" ActionTag="729183440" Tag="63" IconVisible="False" LeftMargin="159.9843" RightMargin="1010.0156" TopMargin="294.0652" BottomMargin="453.9348" FontSize="20" LabelText="可以选择的人物缺陷." ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="190.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="254.9843" Y="463.9348" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1875" Y="0.6041" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="CommentText" ActionTag="2047056306" Tag="64" IconVisible="False" LeftMargin="636.2979" RightMargin="503.7021" TopMargin="377.7893" BottomMargin="350.2107" FontSize="20" LabelText="可以选择更多的天赋，但&#xA;是你要选择更多的缺陷." ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="220.0000" Y="40.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="746.2979" Y="370.2107" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5487" Y="0.4820" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedTalentText" ActionTag="637882284" Tag="65" IconVisible="False" LeftMargin="885.7453" RightMargin="394.2547" TopMargin="3.3877" BottomMargin="744.6123" FontSize="20" LabelText="已选天赋" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="80.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="925.7453" Y="754.6123" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6807" Y="0.9826" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedFlawText" ActionTag="-1606289669" Tag="66" IconVisible="False" LeftMargin="882.5452" RightMargin="397.4548" TopMargin="291.7924" BottomMargin="456.2076" FontSize="20" LabelText="已选缺陷" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="80.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="922.5452" Y="466.2076" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6783" Y="0.6070" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="SelectFlaw_BagPos" ActionTag="728887765" Tag="67" IconVisible="True" LeftMargin="152.6600" RightMargin="1207.3400" TopMargin="319.1677" BottomMargin="448.8323" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="152.6600" Y="448.8323" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1123" Y="0.5844" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedFlaw_BagPos" ActionTag="-1838276716" Tag="68" IconVisible="True" LeftMargin="873.0985" RightMargin="486.9015" TopMargin="319.4900" BottomMargin="448.5100" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="873.0985" Y="448.5100" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6420" Y="0.5840" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="UsedSkillPointText" ActionTag="-2281120" Tag="30" IconVisible="False" LeftMargin="767.1656" RightMargin="584.8344" TopMargin="127.4909" BottomMargin="624.5091" FontSize="16" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="8.0000" Y="16.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="771.1656" Y="632.5091" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="2" G="196" B="2" />
            <PrePosition X="0.5670" Y="0.8236" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="LeftSkillPointText" ActionTag="839423086" Tag="31" IconVisible="False" LeftMargin="762.7189" RightMargin="581.2811" TopMargin="153.3628" BottomMargin="598.6372" FontSize="16" LabelText="15" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="16.0000" Y="16.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="770.7189" Y="606.6372" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="2" G="196" B="2" />
            <PrePosition X="0.5667" Y="0.7899" />
            <PreSize X="0.0000" Y="0.0000" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>