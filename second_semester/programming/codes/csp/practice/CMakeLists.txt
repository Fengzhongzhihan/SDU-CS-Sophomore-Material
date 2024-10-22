cmake_minimum_required(VERSION 3.25)
project(practice)

        set(CMAKE_CXX_STANDARD 14)

        add_executable(practice
                DailyPractice/21-round1/A/amazingTyper.cpp
                DailyPractice/21-round1/A/badKeyTest.cpp
                DailyPractice/21-round1/A/hitAns.cpp
                DailyPractice/21-round1/A/hitB.cpp
                DailyPractice/22-round1/countNum.cpp
                DailyPractice/22-round1/cutCake.cpp
                DailyPractice/22-round1/findHigh.cpp
                DailyPractice/22-round1/pickStars.cpp)

        add_executable(countNum DailyPractice/22-round1/countNum.cpp DailyPractice/22-round1/pickStarsMatrix.cpp)
        add_executable(pickStars DailyPractice/22-round1/pickStars.cpp)
        add_executable(pickStarsMatrix DailyPractice/22-round1/pickStarsMatrix.cpp)
add_executable(RGB DailyPractice/21-round1/B/RGB.cpp)
add_executable(pwStrong DailyPractice/21-round1/B/pwStrong.cpp)
add_executable(noddles DailyPractice/21-round1/B/noddles.cpp)
add_executable(buyVegAgain CCF/buyVegAgain.cpp)
add_executable(deliverFood CCF/deliverFood.cpp)
add_executable(deliverFoodAns CCF/deliverFoodAns.cpp)
add_executable(game SDUOJ/homeWork/week4/game.cpp)
add_executable(jumpjump SDUOJ/homeWork/week3/jumpjump.cpp)
add_executable(strangeElevator SDUOJ/homeWork/week3/strangeElevator.cpp)
add_executable(selectNum SDUOJ/homeWork/week3/selectNum.cpp)
add_executable(test SDUOJ/homeWork/test.cpp)
add_executable(boardProblem SDUOJ/homeWork/week3/boardProblem.cpp)
add_executable(Minggame CCF/Minggame.cpp)
add_executable(MingGameAns CCF/MingGameAns.cpp)
add_executable(pourWater SDUOJ/homeWork/classes/pourWater.cpp)
add_executable(pourWaterAns SDUOJ/homeWork/classes/pourWaterAns.cpp)
add_executable(stringMatch SDUOJ/homeWork/week3/stringMatch.cpp)
add_executable(plantFlower SDUOJ/homeWork/week3/plantFlower.cpp)
add_executable(stringMatchEasy SDUOJ/homeWork/week3/stringMatchEasy.cpp)
add_executable(noodlesAns DailyPractice/21-round1/B/noodlesAns.cpp)
add_executable(cutLine SDUOJ/homeWork/week4/cutLine.cpp)
add_executable(copyer SDUOJ/homeWork/week4/copyer.cpp)
add_executable(copyerAns SDUOJ/homeWork/week4/copyerAns.cpp)
add_executable(copyElse SDUOJ/homeWork/week4/copyElse.cpp)
add_executable(market SDUOJ/homeWork/week4/market.cpp)

add_executable(marketSource SDUOJ/homeWork/week4/marketSource.cpp)
add_executable(FeifeiGambing SDUOJ/BigSimutationScore2/FeifeiGambing.cpp)
add_executable(unzip CCF/unzip.cpp)
add_executable(2013-12-1 CCF/13-12-1.cpp)
add_executable(13-12-2 CCF/13-12-2.cpp)
add_executable(stone SDUOJ/homeWork/week5/stone.cpp)
add_executable(CatCatProtocal SDUOJ/BigSimutationScore2/CatCatProtocal.cpp)
add_executable(stoneAgain SDUOJ/homeWork/week5/stoneAgain.cpp)
add_executable(windows SDUOJ/homeWork/week5/windows.cpp)
add_executable(maxArea SDUOJ/homeWork/week5/maxArea.cpp)
add_executable(maxCommonDivisor SDUOJ/homeWork/week5/maxCommonDivisor.cpp)
add_executable(divisorAgain SDUOJ/homeWork/week5/divisorAgain.cpp)
add_executable(yuanYinJump SDUOJ/homeWork/week6/yuanYinJump.cpp)
add_executable(eraseYuanYIn SDUOJ/homeWork/week6/eraseYuanYIn.cpp)
add_executable(buildRoad SDUOJ/homeWork/week6/buildRoad.cpp)
add_executable(netWorkFeedBack SDUOJ/homeWork/week6/netWorkFeedBack.cpp)
add_executable(waterDesign SDUOJ/homeWork/week6/waterDesign.cpp)
add_executable(watering SDUOJ/homeWork/week7/watering.cpp)
add_executable(array SDUOJ/homeWork/week7/array.cpp)
add_executable(sheep SDUOJ/homeWork/week7/sheep.cpp)
add_executable(magicCube SDUOJ/homeWork/week7/magicCube.cpp)
add_executable(buyFood SDUOJ/homeWork/week8/buyFood.cpp)
add_executable(HWbuyFood SDUOJ/homeWork/week8/HWbuyFood.cpp)
add_executable(crossHole SDUOJ/homeWork/week8/crossHole.cpp)
add_executable(minCost SDUOJ/homeWork/week8/minCost.cpp)
add_executable(shipMeld SDUOJ/homeWork/week8/shipMeld.cpp)
add_executable(2019T3chemistry CCF/2019T3chemistry.cpp)
add_executable(CSP2020fileSystem CCF/CSP2020fileSystem.cpp)
add_executable(YuanyinBack SDUOJ/homeWork/week9/YuanyinBack.cpp)
add_executable(scoreRank SDUOJ/homeWork/week9/scoreRank.cpp)
add_executable(sowYogurt SDUOJ/homeWork/week9/sowYogurt.cpp)
add_executable(msgDeliver SDUOJ/homeWork/week9/msgDeliver.cpp)
add_executable(tour SDUOJ/homeWork/week9/tour.cpp)
add_executable(CatCatMechanics SDUOJ/BigSimutationScore2/CatCatMechanics.cpp)
add_executable(TTandCat SDUOJ/BigSimutationScore2/TTandCat.cpp)
add_executable(inversionPair SDUOJ/homeWork/week10/inversionPair.cpp)
add_executable(SegTree SDUOJ/homeWork/week10/SegTree.cpp)
add_executable(MingGoToSchool SDUOJ/homeWork/week10/MingGoToSchool.cpp)
add_executable(standardNumCnt SDUOJ/homeWork/week10/standardNumCnt.cpp)
add_executable(BIT SDUOJ/homeWork/week10/BIT.cpp)
add_executable(ACrank SDUOJ/homeWork/week10/ACrank.cpp)
add_executable(mars SDUOJ/homeWork/week10/mars.cpp)
add_executable(fishing SDUOJ/SimutationScore5/fishing.cpp)
add_executable(fishing100 SDUOJ/SimutationScore5/fishing100.cpp)
add_executable(WolfAndSheep SDUOJ/SimutationScore5/WolfAndSheep.cpp)
add_executable(climbStep SDUOJ/homeWork/week12/climbStep.cpp)
add_executable(pickNum SDUOJ/homeWork/week12/pickNum.cpp)
add_executable(MatrixNum SDUOJ/homeWork/week12/MatrixNum.cpp)
add_executable(longestPrefix SDUOJ/homeWork/week12/longestPrefix.cpp)
add_executable(CommonFix SDUOJ/homeWork/week12/CommonFix.cpp)
add_executable(0-1bag SDUOJ/homeWork/week13/0-1bag.cpp)
add_executable(MultipleBag SDUOJ/homeWork/week13/MultipleBag.cpp)
add_executable(GroupBag SDUOJ/homeWork/week13/GroupBag.cpp)
add_executable(MaoMaoRotatingHorse SDUOJ/BigSimutationScore2/MaoMaoRotatingHorse.cpp)
add_executable(LinkDebug DailyDebug/LinkDebug.cpp)
add_executable(Calculater DailyDebug/Calculater.cpp)
add_executable(RotatingHorse2 SDUOJ/BigSimutationScore2/RotatingHorse2.cpp)
add_executable(stoneMerge SDUOJ/homeWork/week14/stoneMerge.cpp)
add_executable(bracketSequence SDUOJ/homeWork/week14/bracketSequence.cpp)
add_executable(LongestPalindromeSubsequence SDUOJ/homeWork/week14/LongestPalindromeSubsequence.cpp)
add_executable(hamiltion SDUOJ/homeWork/week14/hamiltion.cpp)
add_executable(MondriansDream SDUOJ/homeWork/week14/MondriansDream.cpp)
add_executable(DanceWithoutHead ACWING/DP/treeDP/DanceWithoutHead.cpp)
add_executable(ski ACWING/DP/dfs/ski.cpp)
add_executable(pickPot ACWING/basic/GREED/pickPot.cpp)
add_executable(groupSeq ACWING/basic/GREED/groupSeq.cpp)
add_executable(coverSeq ACWING/basic/GREED/coverSeq.cpp)
add_executable(mergeGuo ACWING/basic/GREED/mergeGuo.cpp)
add_executable(queueForWater ACWING/basic/GREED/queueForWater.cpp)
add_executable(pickWareHouse ACWING/basic/GREED/pickWareHouse.cpp)
add_executable(NiuNiuPlaying ACWING/basic/GREED/NiuNiuPlaying.cpp)
add_executable(bestCowCover ACWING/basic/binarySearch/bestCowCover.cpp)
add_executable(specialSort ACWING/basic/binarySearch/specialSort.cpp)
add_executable(laserBomb ACWING/basic/sumOrDivision/laserBomb.cpp)
add_executable(IecDec ACWING/basic/sumOrDivision/IecDec.cpp)
add_executable(modalNum ACWING/noSort/modalNum.cpp)
add_executable(QFplayTableGame ACWING/noSort/QFplayTableGame.cpp)
add_executable(negotiatePrice ACWING/noSort/negotiatePrice.cpp)
add_executable(goBang ACWING/noSort/goBang.cpp)
add_executable(charMagic ACWING/noSort/charMagic.cpp)
add_executable(JiJiSubway ACWING/noSort/JiJiSubway.cpp)
add_executable(TreeDiameter ACWING/Tree/TreeDiameter.cpp)
add_executable(TreeDiameterDfs ACWING/Tree/TreeDiameterDfs.cpp)
